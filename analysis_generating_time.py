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
# Define the target metric for this analysis
TARGET_METRIC = 'time_for_init_pop'

input_file = r"D:\dat5.csv"

# Output directory is named based on the target metric
output_dir = rf"D:\output_analysis_{TARGET_METRIC}"
if not os.path.exists(output_dir):
    os.makedirs(output_dir)
    print(f"Directory created: {output_dir}")

# -------------------------------------------------------------------
# 1. Load Data
# -------------------------------------------------------------------
try:
    df = pd.read_csv(input_file)

    # Check if the target column exists
    if TARGET_METRIC not in df.columns:
        print(f"Error: Column '{TARGET_METRIC}' not found in the CSV file.")
        print(f"Available columns: {df.columns.tolist()}")
        exit()

except FileNotFoundError:
    print(f"Error: File not found at {input_file}")
    exit()

# -------------------------------------------------------------------
# 2. Preprocessing - take time_for_init_pop
# -------------------------------------------------------------------
print(f"\nPreparing data for {TARGET_METRIC}...")

group_cols = ['benchmark', 'methods']

# Calculate mean & std dev per benchmark-method
summary_stats_df = df.groupby(group_cols)[TARGET_METRIC].agg(['mean', 'std']).reset_index()

# Rename columns
summary_stats_df.rename(columns={
    'mean': 'Mean_Init_Pop',
    'std': 'Std_Init_Pop'
}, inplace=True)

summary_stats_df.to_csv(os.path.join(output_dir, f"2a_mean_std_dev_{TARGET_METRIC}.csv"), index=False)
print("Mean & Std Dev table saved.")

# -------------------------------------------------------------------
# 3. Pivot Table for Statistical Analysis
# -------------------------------------------------------------------
print("\nCreating pivot table for statistical analysis...")

pivot_df = df.pivot_table(index=['benchmark', 'run-'], columns='methods', values=TARGET_METRIC)
pivot_df.to_csv(os.path.join(output_dir, f"3_pivot_table_for_analysis_{TARGET_METRIC}.csv"))

methods = pivot_df.columns.tolist()
print("Available methods:", methods)

# Check for NaN values
if pivot_df.isnull().sum().sum() > 0:
    print("WARNING: NaN values detected, rows will be dropped.")
    pivot_df = pivot_df.dropna()

# Data matrix for Friedman test
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

with open(os.path.join(output_dir, f"4_friedman_test_result_{TARGET_METRIC}.txt"), 'w') as f:
    f.write(friedman_result_text)

# -------------------------------------------------------------------
# 5. Post-hoc Nemenyi Test
# -------------------------------------------------------------------
if p < 0.05:
    print("Running Post-hoc Nemenyi Test...")

    nemenyi_df = sp.posthoc_nemenyi_friedman(data_matrix)
    nemenyi_df.index = methods
    nemenyi_df.columns = methods

    nemenyi_df.to_csv(os.path.join(output_dir, f"5_nemenyi_test_results_{TARGET_METRIC}.csv"))
    print("Post-hoc Nemenyi Test results saved.")

# -------------------------------------------------------------------
# 6. Autorank & Critical Difference Diagram
# -------------------------------------------------------------------
print("\nGenerating Autorank report and Critical Difference Diagram...")

try:
    # Lower time is better → ascending
    result = autorank(pivot_df, alpha=0.05, order='ascending', verbose=False)

    autorank_report = create_report(result)

    with open(os.path.join(output_dir, f"6_autorank_report_{TARGET_METRIC}.txt"), 'w') as f:
        f.write(autorank_report if autorank_report else "Autorank report is empty.\n")

    result.rankdf.to_csv(os.path.join(output_dir, f"7_autorank_rankings_{TARGET_METRIC}.csv"))

    plt.figure(figsize=(10, max(2, len(methods) * 0.5)))
    plot_stats(result)

    plt.title(f"Critical Difference Diagram ({TARGET_METRIC})", fontsize=14)
    plt.xlabel("Mean Rank", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.6)

    # Ensure smaller rank is on the left
    ax = plt.gca()
    ax.invert_xaxis()

    plt.savefig(os.path.join(output_dir, f"8_cd_diagram_{TARGET_METRIC}.svg"),
                dpi=300, bbox_inches='tight')
    plt.close()

    print("Critical Difference Diagram successfully generated and saved.")

except Exception as e:
    print("\n---!!! FAILED TO GENERATE CD DIAGRAM !!!---")
    print(f"Error: {e}")
    print("-----------------------------------------")

# -------------------------------------------------------------------
# 7. Best Method & Final Summary
# -------------------------------------------------------------------
avg_time_value = summary_stats_df.groupby('methods')['Mean_Init_Pop'].mean()
best_method = avg_time_value.idxmin()

best_method_text = f"\nMethod with the lowest average '{TARGET_METRIC}' = {best_method}\n"
print(best_method_text)

summary_text = f"--- Statistical Analysis Summary ({TARGET_METRIC}) ---\n\n"
summary_text += "== Friedman Test Result ==\n"
summary_text += friedman_result_text
summary_text += "\n== Best Method ==\n"
summary_text += best_method_text

with open(os.path.join(output_dir, f"10_summary_results_{TARGET_METRIC}.txt"), 'w') as f:
    f.write(summary_text)

print(f"\nAnalysis complete. All results saved in: {output_dir}")