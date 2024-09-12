#include "rle.h"
#include <iostream>
#include <fstream>


void compressFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Gagal membuka file untuk kompresi.\n";
        return;
    }

    char currentChar;
    char nextChar;
    int count = 1;

    if (inputFile.get(currentChar)) {
        while (inputFile.get(nextChar)) {
            if (currentChar == nextChar) {
                ++count;
            } else {
                outputFile.write(reinterpret_cast<const char*>(&count), sizeof(count));
                outputFile.write(&currentChar, sizeof(currentChar));
                currentChar = nextChar;
                count = 1;
            }
        }

        outputFile.write(reinterpret_cast<const char*>(&count), sizeof(count));
        outputFile.write(&currentChar, sizeof(currentChar));
    }
    std::cout << "Kompresi selesai.\n";
}