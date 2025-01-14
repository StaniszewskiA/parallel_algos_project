#include "generator.h"
#include <random>
#include <openrand/philox.h>
#include <omp.h>

void generateParallelStd(int size, std::vector<double>& numbers) {
    numbers.resize(size);

    #pragma omp parallel
    {
        std::mt19937 rng(omp_get_thread_num());   
        std::uniform_real_distribution<double> dist(0.0, 1.0);

        #pragma omp for
        for (int i = 0; i < size; ++i) {
            numbers[i] = dist(rng);
        }
    }
}

void generateParallelPhilox(int size, std::vector<double>& numbers) {
    using RNG = openrand::Philox;
    numbers.resize(size);

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        RNG rng(i, 0); 
        numbers[i] = rng.rand<double>();
    }
}
