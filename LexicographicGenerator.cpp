#include "LexicographicGenerator.h"
#include <iostream>
#include <algorithm>

LexicographicGenerator::LexicographicGenerator(std::vector<char> alpha, int length)
    : alphabet(std::move(alpha)), n(length) {
    std::sort(alphabet.begin(), alphabet.end());
}

void LexicographicGenerator::backtrack(std::string& current) const {
    if (current.size() == (size_t)n) {
        std::cout << current << "\n";
        return;
    }

    for (char c : alphabet) {
        current.push_back(c);
        backtrack(current);
        current.pop_back();
    }
}

void LexicographicGenerator::generate() const {
    std::string current;
    backtrack(current);
}