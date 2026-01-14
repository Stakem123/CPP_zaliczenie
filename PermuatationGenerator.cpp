#include "PermutationGenerator.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

PermutationGenerator::PermutationGenerator(int length) : n(length) {}

void PermutationGenerator::generateAndPrint() const {
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);

    long long total = 1;
    for (int i = 1; i <= n; ++i) total *= i;
    std::cout << total << "\n";

    do {
        for (int i = 0; i < n; ++i)
            std::cout << p[i] << (i + 1 == n ? "" : " ");
        std::cout << "\n";
    } while (std::next_permutation(p.begin(), p.end()));
}