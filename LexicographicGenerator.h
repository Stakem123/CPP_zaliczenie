#ifndef LEXICOGRAPHICGENERATOR_H
#define LEXICOGRAPHICGENERATOR_H

#include <vector>
#include <string>

class LexicographicGenerator {
private:
    std::vector<char> alphabet;
    int n;
    void backtrack(std::string& current) const;

public:
    LexicographicGenerator(std::vector<char> alpha, int length);
    void generate() const;
};

#endif