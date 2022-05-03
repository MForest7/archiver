#ifndef DECODER_HPP_INCLUDED
#define DECODER_HPP_INCLUDED

#include <huffman.hpp>
#include <report.hpp>
#include <iostream>
#include <algorithm>
#include <map>

using std::size_t;
using std::istream;
using std::ostream;
using std::map;
using std::pair;

using archive::report;

using namespace huffman;

namespace archive {

class Decoder {
public:
    Decoder(istream& _in);
    Decoder(const Decoder& other) = delete;

    report decode(ostream& out);

private:
    HuffmanTree tree;

    istream* in;
    map <char, size_t> amount;
    size_t length, count_of_codes;
};

}

#endif // DECODER_HPP_INCLUDED