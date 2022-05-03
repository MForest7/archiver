#include <boolio.hpp>

namespace boolio {

BoolOutputBuffer::BoolOutputBuffer(ostream& out) : out(&out) {}

BoolOutputBuffer::~BoolOutputBuffer() {
    while(buffer.size() % SIZE_OF_BYTE != 0)
        buffer.push_back(0);
    print();
}

void BoolOutputBuffer::print() {
    while (buffer.size() >= SIZE_OF_BYTE) {
        unsigned char byte = 0;
        for (size_t i = 0; i < SIZE_OF_BYTE; i++)
            byte |= ((unsigned char)buffer[i] << i);

        if(!out->put(byte))
            throw std::ios_base::failure("Unable to write");

        buffer.erase(buffer.begin(), buffer.begin() + SIZE_OF_BYTE);
    }
}

void BoolOutputBuffer::write(bool bit) {
    buffer.push_back(bit);
    print();
}

void BoolOutputBuffer::append(vector <bool> data) {
    buffer.insert(buffer.end(), data.begin(), data.end());
    print();
}


BoolInputBuffer::BoolInputBuffer(istream& in) : in(&in) {
    index = SIZE_OF_BYTE;
}

void BoolInputBuffer::update() {
    char byte;
    in->get(byte);
    if(in->fail())
        throw std::logic_error("Unable to read");

    buffer.clear();
    index = 0;
    for (size_t i = 0; i < SIZE_OF_BYTE; i++)
        buffer.push_back(((int)byte & (1 << i)) != 0);
}

bool BoolInputBuffer::read() {
    if (index == SIZE_OF_BYTE)
        update();
    return buffer[index++];
}

}