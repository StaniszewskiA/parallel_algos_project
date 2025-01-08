#include "generator.h"
#include <random>
#include <openrand/philox.h>
#include <omp.h>

void generateSequential(int size, std::vector<int>& numbers) {
    std::mt19937 rng(1);
    for (int i = 0; i < size; ++i) {
        numbers[i] = rng();
    }
}

void generateParallel(int size, std::vector<int>& numbers) {
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        openrand::Philox rng(i, 0);
        numbers[i] = rng();
    }
}
