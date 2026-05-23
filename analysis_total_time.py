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
input_file = r"D:\dat5.csv"
output_dir = r"D:\output_analysis_time_all_process"

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
# 2. Preprocessing - extract time_for_all_process
# -------------------------------------------------------------------
print("\nPreparing data for time_for_all_process...")
group_cols = ['benchmark', 'methods']

# Calculate mean & std dev per benchmark-method
summary_stats_df = df.groupby(group_cols)['time_for_all_process'].agg(['mean', 'std']).reset_index()
summary_stats_df.rename(columns={'mean': 'Mean_All_Process', 'std': 'Std_All_Process'}, inplace=True)
summary_stats_df.to_csv(os.path.join(output_dir, "2a_mean_std_dev_time_all_process.csv"), index=False)

print("Mean & Std Dev table saved.")

# -------------------------------------------------------------------
# 3. Pivot Table for Statistical Analysis
# -------------------------------------------------------------------
print("\nCreating pivot table for statistical analysis...")

pivot_df = df.pivot_table(
    index=['benchmark', 'run-'],
    columns='methods',
    values='time_for_all_process'
)

pivot_df.to_csv(os.path.join(output_dir, "3_pivot_table_for_analysis_time_all_process.csv"))

methods = pivot_df.columns.tolist()
print("Available methods:", methods)

# Check NaN
if pivot_df.isnull().sum().sum() > 0:
    print("WARNING: NaN values detected, dropping rows.")
    pivot_df = pivot_df.dropna()

# Data matrix for Friedman Test
data_matrix = pivot_df.values

# -------------------------------------------------------------------
# 4. Friedman Test
# -------------------------------------------------------------------
print("\nRunning Friedman Test...")

stat, p = friedmanchisquare(*[data_matrix[:, i] for i in range(data_matrix.shape[1])])

friedman_result_text = f"Friedman statistic = {stat:.4f}\np-value = {p:.4e}\n"

if p < 0.05:
    friedman_result_text += ">> Significant differences exist among methods (p < 0.05)\n"
else:
    friedman_result_text += ">> No significant differences among methods (p >= 0.05)\n"

print(friedman_result_text)

with open(os.path.join(output_dir, "4_friedman_test_result_time_all_process.txt"), 'w') as f:
    f.write(friedman_result_text)

# -------------------------------------------------------------------
# 5. Post-hoc Nemenyi Test
# -------------------------------------------------------------------
if p < 0.05:
    print("Running Post-hoc Nemenyi Test...")

    nemenyi_df = sp.posthoc_nemenyi_friedman(data_matrix)
    nemenyi_df.index = methods
    nemenyi_df.columns = methods

    nemenyi_df.to_csv(os.path.join(output_dir, "5_nemenyi_test_results_time_all_process.csv"))
    print("Post-hoc Nemenyi Test results saved.")

# -------------------------------------------------------------------
# 6. Autorank & Critical Difference Diagram
# -------------------------------------------------------------------
print("\nGenerating Autorank report and Critical Difference Diagram...")

try:
    result = autorank(pivot_df, alpha=0.05, order='ascending', verbose=True)

    autorank_report = create_report(result)
    with open(os.path.join(output_dir, "6_autorank_report_time_all_process.txt"), 'w') as f:
        f.write(autorank_report if autorank_report else "Autorank report is empty.\n")

    result.rankdf.to_csv(os.path.join(output_dir, "7_autorank_rankings_time_all_process.csv"))

    plt.figure(figsize=(10, max(2, len(methods) * 0.5)))
    plot_stats(result)

    plt.title("Critical Difference Diagram (Time for All Process)", fontsize=14)
    plt.xlabel("Mean Rank", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.6)

    # Ensure smaller rank is on the left
    ax = plt.gca()
    ax.invert_xaxis()

    plt.savefig(
        os.path.join(output_dir, "8_cd_diagram_time_all_process.svg"),
        dpi=300,
        bbox_inches='tight'
    )
    plt.close()

    print("Critical Difference Diagram successfully generated and saved.")

except Exception as e:
    print("\n---!!! FAILED TO GENERATE CD DIAGRAM !!!---")
    print(f"Error: {e}")
    print("-----------------------------------------")

# -------------------------------------------------------------------
# 7. Best Method & Final Summary
# -------------------------------------------------------------------
avg_time_value = summary_stats_df.groupby('methods')['Mean_All_Process'].mean()
best_method = avg_time_value.idxmin()

best_method_text = f"\nMethod with lowest average 'time_for_all_process' = {best_method}\n"
print(best_method_text)

summary_text = "--- Statistical Analysis Summary (Time for All Process) ---\n\n"
summary_text += "== Friedman Test Result ==\n"
summary_text += friedman_result_text
summary_text += "\n== Best Method ==\n"
summary_text += best_method_text

with open(os.path.join(output_dir, "10_summary_results_time_all_process.txt"), 'w') as f:
    f.write(summary_text)

print(f"\nAnalysis complete. All results saved in directory: {output_dir}")