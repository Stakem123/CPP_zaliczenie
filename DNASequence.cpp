#include "DNASequence.h"
#include <iostream>
#include <fstream>
#include <utility>

DNASequence::DNASequence(std::string seq) : sequence(std::move(seq)) {}

void DNASequence::loadFromFasta(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    sequence.clear();
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '>') continue;
        sequence += line;
    }
}

std::pair<DNASequence, DNASequence> DNASequence::loadTwoSequences(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string s1, s2;
    std::getline(file, s1);
    std::getline(file, s2);
    return {DNASequence(s1), DNASequence(s2)};
}

void DNASequence::printNucleotideCount() const {
    int A = 0, C = 0, G = 0, T = 0;
    for (char base : sequence) {
        if (base == 'A') A++;
        else if (base == 'C') C++;
        else if (base == 'G') G++;
        else if (base == 'T') T++;
    }
    std::cout << "A:" << A << " " << "C:" << C << " " << "G:" << G << " " << "T:" << T << "\n";
}

std::string DNASequence::getRNA() const {
    std::string rna = sequence;
    for (char& base : rna)
        if (base == 'T') base = 'U';
    return rna;
}

std::string DNASequence::getReverseComplement() const {
    std::string revComp;
    for (int i = (int)sequence.size() - 1; i >= 0; --i) {
        if (sequence[i] == 'A') revComp += 'T';
        else if (sequence[i] == 'T') revComp += 'A';
        else if (sequence[i] == 'C') revComp += 'G';
        else if (sequence[i] == 'G') revComp += 'C';
    }
    return revComp;
}

int DNASequence::calculateHammingDistance(const DNASequence& other) const {
    int distance = 0;
    for (size_t i = 0; i < sequence.size(); ++i)
        if (sequence[i] != other.sequence[i]) distance++;
    return distance;
}