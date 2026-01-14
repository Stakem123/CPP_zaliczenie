#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATIONGENERATOR_H

class PermutationGenerator {
private:
    int n;

public:
    PermutationGenerator(int length);
    void generateAndPrint() const;
};

#endif