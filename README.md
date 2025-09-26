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

# Expected Output (for my machine)
The program will output the average time taken for each input size in nanoseconds. The output will look something like this:
```
samad@apollo:~/arora$ gcc -O2 -std=c11 Proj-1.c -o lex -lm && ./lex
n=10         theoretical=5       mean=30 ns ,    mean/theoretical=6.51  median=30 ns median/theoretical=6.46
n=100        theoretical=22      mean=97 ns ,    mean/theoretical=4.49  median=97 ns median/theoretical=4.50
n=1000       theoretical=100     mean=401 ns ,   mean/theoretical=4.01  median=409 ns median/theoretical=4.09
n=10000      theoretical=464     mean=1911 ns ,          mean/theoretical=4.12  median=1913 ns median/theoretical=4.12
n=100000     theoretical=2154    mean=9001 ns ,          mean/theoretical=4.18  median=9037 ns median/theoretical=4.19
n=1000000    theoretical=10000   mean=42463 ns ,         mean/theoretical=4.25  median=42440 ns median/theoretical=4.24
n=10000000   theoretical=46416   mean=201050 ns ,        mean/theoretical=4.33  median=200714 ns median/theoretical=4.32
n=100000000  theoretical=215443          mean=806728 ns ,        mean/theoretical=3.74  median=943892 ns median/theoretical=4.38
n=1000000000 theoretical=1000000         mean=2986487 ns ,       mean/theoretical=2.99  median=2983590 ns median/theoretical=2.98
Sum=705610576130502000
```

# Graph
<img width="1000" height="600" alt="theoretical_vs_mean_median" src="https://github.com/user-attachments/assets/ac4b865c-0357-42fb-bec5-f406e4f18620" />


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

