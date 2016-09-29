#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clzcompute.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};
    FILE *fp_time = fopen("result_clock_gettime.txt", "a");

    if (argc < 2) return -1;

    int N = atoi(argv[1]);

    // iterator_clz
    clock_gettime(CLOCK_ID, &start);
    iterator_clz(N);
    clock_gettime(CLOCK_ID, &end);
    fprintf(fp_time, "%d %lf ", N, ((double)(end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec)/ONE_SEC) * 1000000);


    // bin_search_clz
    clock_gettime(CLOCK_ID, &start);
    bin_search_clz(N);
    clock_gettime(CLOCK_ID, &end);
    fprintf(fp_time, "%lf ", ((double)(end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec)/ONE_SEC) * 1000000);


    // byte_shift_clz
    clock_gettime(CLOCK_ID, &start);
    byte_shift_clz(N);
    clock_gettime(CLOCK_ID, &end);
    fprintf(fp_time, "%lf ", ((double)(end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec)/ONE_SEC) * 1000000);


    // recursive_clz
    clock_gettime(CLOCK_ID, &start);
    recursive_clz(N, 16);
    clock_gettime(CLOCK_ID, &end);
    fprintf(fp_time, "%lf\n", ((double)(end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec)/ONE_SEC) * 1000000);
    
    fclose(fp_time);

    return 0;
}
