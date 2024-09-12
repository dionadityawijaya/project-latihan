#include "rle.h"
#include <iostream>
#include <fstream>


void decompressFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Gagal membuka file untuk Dekompresi.\n";
        return;
    }

    char currentChar;
    int count;


    while (inputFile.read(reinterpret_cast<char*>(&count), sizeof(count)) && inputFile.read(&currentChar, sizeof(currentChar))) {
        for (int i = 0; i < count; ++i) {
            outputFile.write(&currentChar, sizeof(currentChar));
        }
    }
    std::cout << "Dekompresi selesai.\n";
    

}


