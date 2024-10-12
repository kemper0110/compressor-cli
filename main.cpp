#include <iostream>
#include "HuffmanCompressor.h"
#include "LZSSCompressor.h"

int main() {
    std::ifstream ifs("../mumu.txt");
    if (!ifs.is_open())
        throw std::runtime_error("File not found");

    std::stringstream iss, pss, oss;
    iss << ifs.rdbuf();

    const auto start = std::chrono::steady_clock::now();
    Huffman::HuffmanCompressor().compress(iss, pss);
    LZSS::LZSSCompressor(1024, 4096).compress(pss, oss);
    const auto end = std::chrono::steady_clock::now();

    std::cout << "compress time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}
