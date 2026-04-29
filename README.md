# GA-Experiments: Evolutionary Optimization for Vehicle Routing Problems

This repository serves as a centralized hub for various experiments and implementations of **Genetic Algorithms (GA)** tailored for the **Vehicle Routing Problem (VRP)**. This project is part of ongoing doctoral research aimed at optimizing evolutionary algorithms through advanced parameter tuning and strategy evaluation.

## Problem Scope
The experiments in this repository cover multiple VRP variants, including:
* **CVRP** (Capacitated Vehicle Routing Problem)
* **Green VRP** (Sustainable routing and fuel consumption optimization)
* Multi-constrained VRP benchmarks.

## Experimental Structure
The project is organized into modular components to systematically analyze the GA lifecycle:

1.  **`parameter-setting/`** (Submodule)
    * **Source Repository:** [cvrp-ga-doe](https://github.com/iksan62/cvrp-ga-doe)
    * Focuses on parameter tuning using **Multi-phase Design of Experiments (DoE)**.
    * Investigates the impact of GA parameters on solution quality.
2.  **`initial-population/`**
    * Studies on population initialization strategies.
    * Focus on the impact of initial population quality dan diversity on the performance of GA.
3.  **`selection-method/`**
    * Implementation and analysis of selection operators like **Roulette Wheel Selection**.
    * Evaluation of selection pressure and its effect on convergence.


## Getting Started
This repository utilizes **Git Submodules** to link specific research modules. To clone the entire project including all sub-modules, use:

```bash
git clone --recursive [https://github.com/iksan62/ga-experiments.git](https://github.com/iksan62/ga-experiments.git)
