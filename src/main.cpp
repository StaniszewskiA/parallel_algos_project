#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <omp.h>
#include "generator.h"

int main() {
    const int dataSize = 1'000'000;
    const int maxThreads = 8;
    std::vector<int> numbers(dataSize);

    auto startSeq = std::chrono::high_resolution_clock::now();
    generateSequential(dataSize, numbers);
    auto endSeq = std::chrono::high_resolution_clock::now();
    double timeSeq = std::chrono::duration<double>(endSeq - startSeq).count();
    std::cout << "Czas sekwencyjny: " << timeSeq << " s\n";

    for (int threadCount = 1; threadCount <= maxThreads; threadCount *= 2) {
        omp_set_num_threads(threadCount);

        auto startPar = std::chrono::high_resolution_clock::now();
        generateParallel(dataSize, numbers);
        auto endPar = std::chrono::high_resolution_clock::now();
        double timePar = std::chrono::duration<double>(endPar - startPar).count();

        double speedup = timeSeq / timePar;
        double efficiency = speedup / threadCount;
        double karpFlatt = (1 - efficiency) / (1 - 1.0 / threadCount);

        std::cout << "\nFor " << threadCount << " threads:\n";
        std::cout << "  Time: " << timePar << " s\n";
        std::cout << "  Speedup: " << speedup << "\n";
        std::cout << "  Efficiency: " << efficiency << "\n";
        std::cout << "  Karp-Flatt: " << karpFlatt << "\n";
    }

    return 0;
}
