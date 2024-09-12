#include "rle.h"

int main(int argc, char const *argv[])
{
    const std::string inputFile = "input.txt";
    const std::string compressedFile = "compressed.bin";
    const std::string deccompressedFile = "decompressed.txt";

    compressFile(inputFile, compressedFile);
    decompressFile(compressedFile, deccompressedFile);

    
    return 0;
}
