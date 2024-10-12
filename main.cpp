#include <iostream>
#include "HuffmanCompressor.h"
#include "LZSSCompressor.h"

int main() {
    std::ifstream ifs("../mumu.txt");
    if (!ifs.is_open())
        throw std::runtime_error("File not found");
    ifs.seekg(0, std::ios::end);
    const auto size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    std::cout << "initial size is: " << size << '\n';

    std::stringstream pss, oss;
    Huffman::HuffmanCompressor().compress(ifs, pss);
    LZSS::LZSSCompressor(256, 2048).compress(pss, oss);

    std::string compress_result = oss.str();
    std::cout << "compressed size: " << compress_result.size() << '\n';

    const auto reduce = (double) compress_result.size() / size - 1.0;
    std::cout << reduce * 100 << "% file size lost" << '\n';
    // expected loss: ~35%
}
