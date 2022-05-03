#ifndef BOOLIO_HPP_INCLUDED
#define BOOLIO_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <exception>

using std::size_t;
using std::istream;
using std::ostream;
using std::vector;

namespace boolio {

class BoolOutputBuffer {
public:
    BoolOutputBuffer(ostream& out);
    ~BoolOutputBuffer();
    BoolOutputBuffer(const BoolOutputBuffer& other) = delete;

    void write(bool bit);

    void append(vector <bool> data);

private:
    static const size_t SIZE_OF_BYTE = 8;

    vector <bool> buffer;
    ostream* out;

    void print();
};

class BoolInputBuffer {
public:
    BoolInputBuffer(istream& in);
    ~BoolInputBuffer() = default;

    bool read();

private:
    static const size_t SIZE_OF_BYTE = 8;

    vector <bool> buffer;
    size_t index;
    istream* in;

    void update();
};

}

#endif // BOOLIO_HPP_INCLUDED