# Reproducibility Code and Data
**Initial Population Strategies in Genetic Algorithm for CVRP**

## Overview

This repository provides the complete implementation, datasets, and analysis scripts required to reproduce the experimental results presented in the study on **initial population strategies in Genetic Algorithms (GA)** for the Capacitated Vehicle Routing Problem (CVRP).

The repository includes:

- C++ implementations of initialization strategies  
- Aggregated simulation datasets  
- Python scripts for statistical analysis  

---

## Code Availability

### C++ Implementation

The following source files implement the initial population generation methods:

- `CANN.cpp` — Constraint-Adaptive Nearest Neighbor  
- `MKNN.cpp` — Multi k-Nearest Neighbor  
- `HSIBAL.cpp` — Hybrid Seeding Initialization-Balanced
- `HSILOW.cpp` — Hybrid Seeding Initialization-Low 
- `HSIMIN.cpp` — Hybrid Seeding Initialization-Minimal  

All implementations generate feasible solutions respecting CVRP constraints.

---

## Data Availability

The repository includes aggregated results produced from multiple simulation runs:

- `datbest.csv` — Best objective value per generation (per run)  
- `dat_avg.csv` — Average objective value per generation (per run)  
- `dat2.csv` — Genetic diversity per generation (per run)  
- `dat5.csv` — Computation time data  

Supporting file:

- `Benchmark_Data_Reference.txt` — Predefined benchmark configurations  
- `Statistical test results.zip` — Results of statistical analyses  

---

## Experimental Reproducibility

### Simulation Procedure

To reproduce the simulation results:

1. Select a benchmark instance from `Benchmark_Data_Reference.txt`.  
2. Copy the corresponding data block into the target C++ file under the initialization section.  
3. Set the algorithm parameters (e.g., population size, number of generations).  
4. Compile and execute using a standard C++ compiler (C++14/17 recommended).  

Output: The C++ program produces detailed CSV logs (e.g., FoG(CANN)=X-n1001-k43...csv) containing generation-by-generation fitness traces and the best route structures.
---

### Statistical Analysis

Python scripts are provided to reproduce all analytical results:

- Initial population analysis:  
  `analysis_initial_best.py`, `analysis_initial_avg.py`,  
  `analysis_initial_diversity.py`, `analysis_generating_time.py`  

- Final and evolutionary analysis:  
  `analysis_final_best.py`, `analysis_final_mean.py`,  
  `analysis_final_diversity.py`, `analysis_evol_time.py`,  
  `analysis_total_time.py`  

Required Python packages: pandas, numpy, scipy, statsmodels, matplotlib, seaborn
## Methodological Scope

The experiments evaluate initialization strategies with respect to:

- Initial solution quality (best and mean objective values)  
- Population diversity  
- Evolutionary performance  
- Computational efficiency (initialization, evolution, and total time)  

---

## Requirements

- **Simulation:** C++ compiler (Visual Studio 2022 or equivalent)  
- **Analysis:** Python ≥ 3.8  

---

## License

This repository is made available under the MIT License for academic and research purposes.

---

## Citation

If you use this repository, please cite the associated publication on **Resolving the Quality-Diversity Trade-Off in Genetic Algorithms: A Multi-K Nearest Neighbor Initialization for the CVRP**.
