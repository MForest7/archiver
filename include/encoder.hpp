#ifndef ENCODER_HPP_INCLUDED
#define ENCODER_HPP_INCLUDED

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

using std::cout;
using std::endl;

namespace archive {

class Encoder {
public:
    Encoder(istream& _in);
    Encoder(const Encoder& other) = delete;

    report encode(ostream& out);

private:
    HuffmanTree tree;

    istream* in;
    map <char, size_t> amount;
    size_t length;
};

}

#endif // ENCODER_HPP_INCLUDED