#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#include<time.h>

#include "../ht/hash_table.h"
#include "../utils/hash_table_utils.h"

#define INSERTIONS 100000
#define TEST_ITER 20


/*
 * Elapsed time in nanoseconds
 */
long long timediff(struct timespec* end, struct timespec* start) {
    return (end->tv_sec - start->tv_sec) * 1000000000LL + 
        (end->tv_nsec - start->tv_nsec);
}


double ratio_avg(size_t size, double ratio[static size]) {
    double avg = 0;
    for (size_t i = 0; i < size; i++) {
        avg += ratio[i];
    }
    return avg / size;
}


double ratio_std(size_t size, double ratio[static size]) {
    double std = 0;
    double avg = ratio_avg(size, ratio);

    for (size_t i = 0; i < size; i++) {
        std = pow(ratio[i] - avg, 2);
    }

    return sqrt(std / size);
}


void init_ratio_vector(size_t size, double ratio[static size]) {
    for (size_t i = 0; i < size; i++) {
        ratio[i] = 0.0;
    }
}


void normalize_ratio_vector(size_t size, double ratio[static size]) {
    for (size_t i = 0; i < INSERTIONS; i++) {
        ratio[i] /= TEST_ITER;
    }
}


int main(void) {

    struct timespec start, end;

    double ratio[INSERTIONS];

    init_ratio_vector(INSERTIONS, ratio);

    for (int j = 0; j < TEST_ITER; j++) {
        HashTable ht;
        ht_init(&ht);
        for (int i = 0; i < INSERTIONS; i++) {
            clock_gettime(CLOCK_MONOTONIC, &start);

            ht_insert(&ht, i, "");

            clock_gettime(CLOCK_MONOTONIC, &end);

            long long insertion_time = timediff(&end, &start);
            double load_factor = (double)i / TABLE_SIZE;
            double current_ratio = (double)insertion_time / (load_factor + 1);

            ratio[i] += current_ratio;
        }

        ht_free(&ht);
    }

    normalize_ratio_vector(INSERTIONS, ratio);


    double average = ratio_avg(INSERTIONS, ratio);
    double std = ratio_std(INSERTIONS, ratio);

    printf("Average ratio: %f\tStandard deviation ratio: %f\n", average, std);



}

