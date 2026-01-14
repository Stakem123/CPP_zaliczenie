#ifndef DNASEQUENCE_H
#define DNASEQUENCE_H

#include <string>
#include <vector>

class DNASequence {
private:
    std::string sequence;

public:
    DNASequence() = default;
    DNASequence(std::string seq);

    void loadFromFasta(const std::string& filePath);
    static std::pair<DNASequence, DNASequence> loadTwoSequences(const std::string& filePath);
    void printNucleotideCount() const;
    std::string getRNA() const;
    std::string getReverseComplement() const;
    int calculateHammingDistance(const DNASequence& other) const;
};

#endif