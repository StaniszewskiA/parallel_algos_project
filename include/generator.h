#ifndef GENERATOR_H
#define GENRATOR_H

#include <vector>

void generateParallelStd(int size, std::vector<int>& numbers);
void generateParallelPhilox(int size, std::vector<int>& numbers);

#endif // GENERATOR_H