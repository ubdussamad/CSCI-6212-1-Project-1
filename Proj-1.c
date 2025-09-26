// hw-1.c
// Sam Ul Haque (G20774456)
// Compile and run with:
// gcc -O2 -std=c11 Proj-1.c -o lex -lm && ./lex
// -O2 is important to get realistic timings
// -lm is needed for the math library
#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define _N_ 10000000000L // maximum n to test
#define RUNS 1000.       // number of times to run algo for each n
volatile uint64_t Sum;  // volatile keeps work from being optimized out

// Function to compute difference in nanoseconds between two timespecs
static inline int64_t nsec_diff(struct timespec a, struct timespec b){
    return (a.tv_sec - b.tv_sec)*1000000000LL + (a.tv_nsec - b.tv_nsec);
}

// This is the main profiled algorithm
static inline int64_t run_once(int n){
    int j = 2;
    long long step = llround(cbrt((double)n) * log((double)n)); // step size since step is constant for given n
    if (step < 1) step = 1; // ensure step is at least 1 to avoid infinite loop

    struct timespec t0, t1; // time points before and after
    clock_gettime(CLOCK_MONOTONIC_RAW, &t0);

    // Algorithm to be profiled
    while (j < n) {
        int k = j;
        while (k < n) {
            Sum += (uint64_t)k;
            k += (int)step;
        }
        j <<= 1; // bit shift left is equivalent to j *= 2 (faster than power function)
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    return nsec_diff(t1, t0);
}

// Comparison function for qsort
static int cmp_i64(const void *a, const void *b){
    int64_t x = *(const int64_t*)a, y = *(const int64_t*)b;
    return (x>y)-(x<y);
}

int main(void){
    for (long int n = 10; n < _N_; n *= 10) {

        // Allocate array to hold timing results
        int64_t *t = malloc((size_t)RUNS * sizeof(int64_t));
        if (!t) return 1;

        // Main loop that runs the function (that runs the algorithm)
        long double sum = 0;

        // Calculate mean
        for (int i = 0; i < RUNS; ++i){ t[i] = run_once(n); sum += t[i]; }
        double mean_ns = (double)(sum / RUNS);

        // median
        int64_t *tmp = malloc((size_t)RUNS * sizeof(int64_t));
        memcpy(tmp, t, (size_t)RUNS * sizeof(int64_t));
        qsort(tmp, RUNS, sizeof(int64_t), cmp_i64);
        double median_ns = (RUNS & 1) ? (double)tmp[RUNS/2] : (tmp[RUNS/2-1] + tmp[RUNS/2]) / 2.0;


        double theoretical = ( (  4* pow(n , (2.0/3.0) )) / log(n)   );
        printf(
            "n=%-10ld theoretical=%.0f \t mean=%.0f ns , \t mean/theoretical=%.2f  median=%.0f ns median/theoretical=%.2f\n",
            n,
            theoretical,            // theoretical time complexity
            mean_ns,                // expermentally measured mean time
            mean_ns/theoretical,    // ratio of mean to theoretical (to find the scaling factor)
            median_ns,              // experimentally measured median time  
            median_ns/theoretical   // ratio of median to theoretical (to find the scaling factor
        );

        free(tmp); free(t);
    }
    fprintf(stderr, "Sum=%llu\n", (unsigned long long)Sum);
    return 0;
}
