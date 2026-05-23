import pandas as pd
from scipy.stats import friedmanchisquare
import scikit_posthocs as sp
import numpy as np
import matplotlib.pyplot as plt
from autorank import autorank, plot_stats, create_report
import os

# -------------------------------------------------------------------
# 0. Setup Path
# -------------------------------------------------------------------
input_file = r"D:\datbest.csv"

# Change output directory to reflect Generation 0 analysis
output_dir = r"D:\output_analysis_Init_best"
if not os.path.exists(output_dir):
    os.makedirs(output_dir)
    print(f"Directory created: {output_dir}")

# -------------------------------------------------------------------
# 1. Load Data
# -------------------------------------------------------------------
try:
    df = pd.read_csv(input_file)
except FileNotFoundError:
    print(f"Error: File not found at {input_file}")
    exit()

# -------------------------------------------------------------------
# 2. Preprocessing & Get Generation 0 Data (Initial Population)
# -------------------------------------------------------------------
print("\nExtracting objective values for Generation 0 (Initial Population)...")

run_cols = [f'run-{i}' for i in range(1, 21)]
group_cols = ['benchmark', 'methods']

# --- MAIN CHANGE ---
try:
    # Filter data to keep ONLY generation = 0
    gen0_df = df[df['generations'] == 1].copy()
except KeyError:
    print("Error: Column 'generation' not found. Please check column name.")
    exit()

# Check if empty
if gen0_df.empty:
    print("Error: No data found for 'generation == 0'.")
    exit()

# Handle duplicates
if gen0_df.duplicated(subset=group_cols).any():
    print("Warning: Duplicate benchmark-method entries found for generation 0. Keeping the first occurrence.")
    gen0_df = gen0_df.drop_duplicates(subset=group_cols, keep='first')

# Use generation 0 data
global_best_df = gen0_df.drop(columns=['generation'], errors='ignore')

global_best_df.to_csv(os.path.join(output_dir, "2_data_generation_0.csv"), index=False)
print("Generation 0 data successfully extracted and saved.")

# Calculate mean and std deviation
global_best_df['mean_objective'] = global_best_df[run_cols].mean(axis=1)
global_best_df['std_dev_objective'] = global_best_df[run_cols].std(axis=1)

# Save summary table
summary_stats_df = global_best_df[['benchmark', 'methods', 'mean_objective', 'std_dev_objective']].copy()
summary_stats_df.rename(columns={
    'mean_objective': 'Mean_Objective_Value_Gen0',
    'std_dev_objective': 'Std_Dev_Objective_Value_Gen0'
}, inplace=True)

summary_stats_df.sort_values(by=['benchmark', 'methods'], inplace=True)
summary_stats_df.to_csv(os.path.join(output_dir, "2a_mean_std_dev_table_generation_0.csv"), index=False)
print("\nMean and Std Dev table for Generation 0 saved.")

# -------------------------------------------------------------------
# 3. Pivot Table for Statistical Analysis
# -------------------------------------------------------------------
print("\nCreating pivot table for statistical analysis...")
pivot_df = global_best_df.pivot_table(index='benchmark', columns='methods', values='mean_objective')
pivot_df.to_csv(os.path.join(output_dir, "3_pivot_table_for_analysis_generation_0.csv"))

methods = pivot_df.columns.tolist()
print("Available methods:", methods)

# Diagnostic: check NaN values
if pivot_df.isnull().sum().sum() > 0:
    print("\nWARNING: NaN values detected in pivot table. This may cause errors.")
    # Optional:
    # pivot_df.dropna(inplace=True)
    # print("Rows with NaN removed.")
else:
    print("\nInfo: No NaN values found. Proceeding.")

data_matrix = pivot_df.values

# -------------------------------------------------------------------
# 3a. Prepare DataFrame for Autorank (use raw Gen 0 data)
# -------------------------------------------------------------------
print("\nPreparing Generation 0 raw data for Autorank...")

long_gen0_df = global_best_df.melt(
    id_vars=['benchmark', 'methods'],
    value_vars=run_cols,
    var_name='run',
    value_name='objective'
)

pivot_runs_df = long_gen0_df.pivot_table(
    index=['benchmark', 'run'],
    columns='methods',
    values='objective'
)

pivot_runs_df.to_csv(os.path.join(output_dir, "3b_pivot_table_runs_for_autorank_gen0.csv"))
print("Pivot data for Autorank (Generation 0) created.")

# -------------------------------------------------------------------
# 4. Friedman Test
# -------------------------------------------------------------------
print("\nRunning Friedman Test...")
try:
    stat, p = friedmanchisquare(*[data_matrix[:, i] for i in range(data_matrix.shape[1])])
    friedman_result_text = f"Friedman statistic = {stat:.4f}\np-value = {p:.4f}\n"

    if p < 0.05:
        friedman_result_text += ">> Significant differences exist among methods (p < 0.05)\n"
    else:
        friedman_result_text += ">> No significant differences among methods (p >= 0.05)\n"

except ValueError as e:
    print(f"Error running Friedman test: {e}")
    friedman_result_text = f"Failed to run Friedman test. Error: {e}\n"
    p = 1.0

print(friedman_result_text)

with open(os.path.join(output_dir, "4_friedman_test_result_generation_0.txt"), 'w') as f:
    f.write(friedman_result_text)

# -------------------------------------------------------------------
# 5. Post-hoc Nemenyi Test
# -------------------------------------------------------------------
if p < 0.05:
    print("Running Post-hoc Nemenyi Test...")
    try:
        nemenyi_df = sp.posthoc_nemenyi_friedman(data_matrix)
        nemenyi_df.index = methods
        nemenyi_df.columns = methods
        nemenyi_df.to_csv(os.path.join(output_dir, "5_nemenyi_test_results_generation_0.csv"))
        print("Post-hoc Nemenyi Test results saved.")
    except Exception as e:
        print(f"Error running Nemenyi test: {e}")
else:
    print("p-value >= 0.05, skipping Nemenyi test.")

# -------------------------------------------------------------------
# 6. Autorank & Critical Difference Diagram
# -------------------------------------------------------------------
print("\nGenerating Autorank report and Critical Difference Diagram...")
try:
    result = autorank(pivot_runs_df, alpha=0.05, order='ascending', verbose=True)

    autorank_report = create_report(result)
    with open(os.path.join(output_dir, "6_autorank_report_generation_0.txt"), 'w') as f:
        f.write(autorank_report if autorank_report else "Autorank report is empty.\n")

    result.rankdf.to_csv(os.path.join(output_dir, "7_autorank_rankings_generation_0.csv"))

    plt.figure(figsize=(10, max(2, len(methods) * 0.5)))
    plot_stats(result)
    plt.title("Critical Difference Diagram (Generation 0 Objective)", fontsize=14)
    plt.xlabel("Mean Rank", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.6)

    ax = plt.gca()
    ax.invert_xaxis()

    plt.savefig(os.path.join(output_dir, "8_cd_diagram_generation_0.svg"), dpi=300, bbox_inches='tight')
    plt.close()

    print("Critical Difference Diagram successfully generated and saved.")

except Exception as e:
    print("\n---!!! FAILED TO GENERATE CD DIAGRAM !!!---")
    print(f"Error: {e}")
    print("-----------------------------------------")

# -------------------------------------------------------------------
# 7. Best Method & Final Summary
# -------------------------------------------------------------------
avg_objective_value = pivot_df.mean(axis=0)
best_method = avg_objective_value.idxmin()

best_method_text = f"\nMethod with lowest average 'generation 0 objective value' = {best_method}\n"
print(best_method_text)

summary_text = "--- Statistical Analysis Summary (Generation 0 Objective) ---\n\n"
summary_text += "== Friedman Test Result (based on mean across runs) ==\n"
summary_text += friedman_result_text
summary_text += "\n== Best Method (based on mean of mean values) ==\n"
summary_text += best_method_text
summary_text += "\nNote: Refer to Autorank report (6_...) and CD Diagram (8_...) for more detailed statistical comparison."

with open(os.path.join(output_dir, "10_summary_results_generation_0.txt"), 'w') as f:
    f.write(summary_text)

print(f"\nAnalysis complete. All results saved in directory: {output_dir}")