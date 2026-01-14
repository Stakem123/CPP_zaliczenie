#include "DNASequence.h"
#include "PermutationGenerator.h"
#include "LexicographicGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // 1. DNA Count
    DNASequence dna1;
    dna1.loadFromFasta("rosalind_dna.txt");
    dna1.printNucleotideCount();

    // 2. RNA Transliteration
    DNASequence dna2;
    dna2.loadFromFasta("rosalind_rna.txt");
    std::cout << dna2.getRNA() << "\n";

    // 3. Reverse Complement
    DNASequence dna3;
    dna3.loadFromFasta("rosalind_revc.txt");
    std::cout << dna3.getReverseComplement() << "\n";

    // 4. Hamming Distance
    auto [s, t] = DNASequence::loadTwoSequences("rosalind_hamm.txt");
    std::cout << s.calculateHammingDistance(t) << "\n";

    // 5. Permutations
    std::ifstream file_perm("rosalind_perm.txt");
    int n_perm;
    if (file_perm >> n_perm) {
        PermutationGenerator gen(n_perm);
        gen.generateAndPrint();
    }

    // 6. Lexicographic
    std::ifstream file_lex("rosalind_lexf.txt");
    std::string line, symbol;
    if (std::getline(file_lex, line)) {
        std::stringstream ss(line);
        std::vector<char> alpha;
        while (ss >> symbol) alpha.push_back(symbol[0]);

        int n_lex;
        if (file_lex >> n_lex) {
            LexicographicGenerator lexGen(alpha, n_lex);
            lexGen.generate();
        }
    }

    return 0;
}