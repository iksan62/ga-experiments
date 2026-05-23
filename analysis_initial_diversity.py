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
# Input file path (make sure your CSV contains columns: 'generations', 'benchmark', 'methods', run-1 ... run-20, etc.)
input_file = r"D:\dat2.csv"

# Create output directory for INITIAL population genetic diversity analysis
output_dir = r"D:\output_analysis_init_diversity"
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
# 2. Preprocessing & Get Diversity Values from INITIAL Population
# -------------------------------------------------------------------
print("\nFiltering data to obtain genetic diversity values from INITIAL population (generations == 1)...")

# Filter for initial generation
df_initial = df[df['generations'] == 1].copy()

if df_initial.empty:
    print("Error: No data found for 'generations == 1'. Please check your CSV file.")
    exit()

print("Initial population diversity data successfully filtered.")

# Run columns
run_cols = [f'run-{i}' for i in range(1, 21)]
group_cols = ['benchmark', 'methods']

# Compute average diversity across runs per benchmark & method
initial_pop_df = df_initial.groupby(group_cols)[run_cols].mean().reset_index()
initial_pop_df.to_csv(os.path.join(output_dir, "2_data_initial_pop_diversity.csv"), index=False)

# Compute mean & std deviation
initial_pop_df['mean_diversity'] = initial_pop_df[run_cols].mean(axis=1)
initial_pop_df['std_dev_diversity'] = initial_pop_df[run_cols].std(axis=1)

summary_stats_df = initial_pop_df[['benchmark', 'methods', 'mean_diversity', 'std_dev_diversity']].copy()
summary_stats_df.rename(columns={
    'mean_diversity': 'Mean_Diversity_Value',
    'std_dev_diversity': 'Std_Dev_Diversity_Value'
}, inplace=True)

summary_stats_df.sort_values(by=['benchmark', 'methods'], inplace=True)
summary_stats_df.to_csv(os.path.join(output_dir, "2a_mean_std_dev_table_initial_pop_diversity.csv"), index=False)

print("\nMean and Std Dev table for Genetic Diversity (Initial Population) saved.")

# -------------------------------------------------------------------
# 3. Pivot Table for Statistical Analysis
# -------------------------------------------------------------------
print("\nCreating pivot table for diversity analysis (Initial Population)...")

pivot_df = initial_pop_df.pivot_table(index='benchmark', columns='methods', values='mean_diversity')
pivot_df.to_csv(os.path.join(output_dir, "3_pivot_table_for_analysis_diversity_initial.csv"))

methods = pivot_df.columns.tolist()
print("Available methods:", methods)

if pivot_df.isnull().sum().sum() > 0:
    print("\nWARNING: NaN values detected in pivot table.")
else:
    print("\nInfo: No NaN values found. Proceeding with analysis.")

data_matrix = pivot_df.values

# -------------------------------------------------------------------
# 3a. Prepare DataFrame for Autorank
# -------------------------------------------------------------------
print("\nPreparing data for Autorank (Initial Population)...")

# Convert to long format
long_df = df_initial.melt(
    id_vars=['benchmark', 'methods'],
    value_vars=run_cols,
    var_name='run',
    value_name='diversity'
)

# Average per benchmark, method, run
long_avg = long_df.groupby(['benchmark', 'methods', 'run'])['diversity'].mean().reset_index()

# Pivot for autorank
pivot_runs_df = long_avg.pivot_table(
    index=['benchmark', 'run'],
    columns='methods',
    values='diversity'
)

pivot_runs_df.to_csv(os.path.join(output_dir, "3b_pivot_table_runs_for_autorank_diversity_initial.csv"))
print("Pivot data for Autorank (Initial Population) created.")

# -------------------------------------------------------------------
# 4. Friedman Test
# -------------------------------------------------------------------
print("\nRunning Friedman Test for diversity (Initial Population)...")

stat, p = friedmanchisquare(*[data_matrix[:, i] for i in range(data_matrix.shape[1])])

friedman_result_text = f"Friedman statistic = {stat:.4f}\np-value = {p:.4f}\n"

if p < 0.05:
    friedman_result_text += ">> Significant differences exist among methods (p < 0.05)\n"
else:
    friedman_result_text += ">> No significant differences among methods (p >= 0.05)\n"

print(friedman_result_text)

with open(os.path.join(output_dir, "4_friedman_test_result_diversity_initial.txt"), 'w') as f:
    f.write(friedman_result_text)

# -------------------------------------------------------------------
# 5. Post-hoc Nemenyi Test
# -------------------------------------------------------------------
if p < 0.05:
    print("Running Post-hoc Nemenyi Test...")
    nemenyi_df = sp.posthoc_nemenyi_friedman(data_matrix)
    nemenyi_df.index = methods
    nemenyi_df.columns = methods
    nemenyi_df.to_csv(os.path.join(output_dir, "5_nemenyi_test_results_diversity_initial.csv"))
    print("Post-hoc Nemenyi Test results saved.")

# -------------------------------------------------------------------
# 6. Autorank & Critical Difference Diagram
# -------------------------------------------------------------------
print("\nGenerating Autorank report and Critical Difference Diagram for diversity (Initial Population)...")

try:
    result = autorank(pivot_runs_df, alpha=0.05, order='descending', verbose=False)

    # Sort ranking table by meanrank
    if hasattr(result, 'rankdf') and result.rankdf is not None:
        result.rankdf.sort_values(by='meanrank', ascending=True, inplace=True)

    autorank_report = create_report(result)

    with open(os.path.join(output_dir, "6_autorank_report_diversity_initial.txt"), 'w') as f:
        f.write(autorank_report if autorank_report else "Autorank report is empty.\n")

    result.rankdf.to_csv(os.path.join(output_dir, "7_autorank_rankings_diversity_initial.csv"))

    plt.figure(figsize=(10, max(2, len(methods) * 0.5)))
    plot_stats(result)
    plt.title("Critical Difference Diagram (Initial Population Genetic Diversity)", fontsize=14)
    plt.xlabel("Mean Rank", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.6)

    # Ensure smaller rank is on the left
    ax = plt.gca()
    ax.invert_xaxis()

    plt.savefig(os.path.join(output_dir, "8_cd_diagram_diversity_initial.svg"), dpi=300, bbox_inches='tight')
    plt.close()

    print("Critical Difference Diagram for diversity successfully generated and saved.")

except Exception as e:
    print("\n---!!! FAILED TO GENERATE CD DIAGRAM FOR DIVERSITY (INITIAL POPULATION) !!!---")
    print(f"Error: {e}")
    print("-----------------------------------------")

# -------------------------------------------------------------------
# 7. Best Method & Final Summary
# -------------------------------------------------------------------
avg_diversity_value = pivot_df.mean(axis=0)
best_method = avg_diversity_value.idxmax()

best_method_text = f"\nMethod with highest average genetic diversity (Initial Population) = {best_method}\n"
print(best_method_text)

summary_text = "--- Statistical Analysis Summary (Initial Population Genetic Diversity) ---\n\n"
summary_text += "== Friedman Test Result ==\n"
summary_text += friedman_result_text
summary_text += "\n== Best Method ==\n"
summary_text += best_method_text

with open(os.path.join(output_dir, "10_summary_results_diversity_initial.txt"), 'w') as f:
    f.write(summary_text)


print(f"\nAnalysis complete. All results saved in directory: {output_dir}")