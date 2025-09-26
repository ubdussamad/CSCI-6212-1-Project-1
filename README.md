# CSCI-6212-1-Project-1
The repo contains code that runs the algorithm for input size ranging from 10 to 10000000000. For each input size, the algorithm is run 1000 times and the time taken for each run is recorded. The mean.median time taken for each input size is then calculated and printed to the console.

# Code Explanation
The code is written in C and performs the following tasks:
1. It defines constants for the maximum input size (`_N_`) and the number of runs to do for each value `_N_` (`RUNS`).
2. It includes necessary libraries for input/output operations, memory allocation, time measurement, and mathematical functions.
3. It defines a function `nsec_diff` to compute the difference in nanoseconds between two `timespec` structures.
4. In the `main` function, it iterates over input sizes from 10 to `_N_`, multiplying by 10 each time.
5. For each input size, it allocates an array to hold timing results and runs the algorithm `RUNS` times, recording the time taken for each run.
6. It calculates the mean and median time taken for each input size and prints the results to the console.
7. It defines a function run_once that runs the actual algorithm given in the problem statement and computers how long it took to run it for a given input size n.

 The section below is the man algorithm that we're profiling which is inside a function for better code readability.
 https://github.com/ubdussamad/CSCI-6212-1-Project-1/blob/97ab3b912038b1b4ba6bdb88a4fc7d766d6edfe2/Proj-1.c#L33-L41

The section below runs the function above a thosand times for each value of n. https://github.com/ubdussamad/CSCI-6212-1-Project-1/blob/97ab3b912038b1b4ba6bdb88a4fc7d766d6edfe2/Proj-1.c#L64

Others are ju8st helper functions.

# Running the Code
To run the code, follow these steps:
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Open a terminal and compile the code using the following command:
   ```bash
   gcc -O2 -std=c11 Proj-1.c -o lex -lm
   ```
4. Run the compiled program using the command:
   ```bash
   ./lex
   ``` 

# Expected Output (for MY machine)
The program will output the average time taken for each input size in nanoseconds. The output will look something like this:
```
samad@apollo:~/arora$ gcc -O2 -std=c11 Proj-1.c -o lex -lm && ./lex
n=10         theoretical=8       mean=87 ns ,    mean/theoretical=10.79  median=86 ns median/theoretical=10.67
n=100        theoretical=19      mean=271 ns ,   mean/theoretical=14.49  median=269 ns median/theoretical=14.37
n=1000       theoretical=58      mean=1161 ns ,          mean/theoretical=20.06  median=1177 ns median/theoretical=20.33
n=10000      theoretical=202     mean=3701 ns ,          mean/theoretical=18.36  median=2588 ns median/theoretical=12.84
n=100000     theoretical=749     mean=10360 ns ,         mean/theoretical=13.84  median=9044 ns median/theoretical=12.08
n=1000000    theoretical=2895    mean=42400 ns ,         mean/theoretical=14.64  median=42374 ns median/theoretical=14.64
n=10000000   theoretical=11519   mean=200967 ns ,        mean/theoretical=17.45  median=200717 ns median/theoretical=17.42
n=100000000  theoretical=46783   mean=671909 ns ,        mean/theoretical=14.36  median=638936 ns median/theoretical=13.66
n=1000000000 theoretical=193020          mean=2985157 ns ,       mean/theoretical=15.47  median=2983662 ns median/theoretical=15.46
```

# Graph
<img width="1000" height="600" alt="theoretical_vs_mean_median" src="https://github.com/user-attachments/assets/f566bef0-4253-4a63-bbc7-1eeda283942a" />


# Machine Specifications
The code was run on a machine with the following specifications:

- System specs:
    - Linux Version: 6.14.0-29-generic
    - Architecture: x86_64
    - CPU Model: Intel(R) Xeon(R) Silver 4316 CPU @ 2.30GHz
    - CPU(s): 40
    - Memory: 64 GiB
    - BogoMIPS: 4600.00
    - Caches (sum of all):         
        - L1d:                       960 KiB (20 instances)
        - L1i:                       640 KiB (20 instances)
        - L2:                        25 MiB (20 instances)
        - L3:                        30 MiB (1 instance)

- Environment:
    - Distributor ID: Ubuntu
    - Description:    Ubuntu 24.04.2 LTS
    - Release:        24.04
    - Codename:       noble

