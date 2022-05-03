#include <decoder.hpp>

namespace archive {

Decoder::Decoder(istream& _in) : in(&_in) {
    in->read((char*)&count_of_codes, sizeof(size_t));

    length = 0;
    for (size_t i = 0; i < count_of_codes; i++) {
        char key;
        size_t number;

        in->get(key);
        in->read((char*)&number, sizeof(size_t));
        
        amount[key] = number;
        length += number;
    }

    tree = HuffmanTree(amount);
}

report Decoder::decode(ostream& out) {
    size_t additional = 2 * sizeof(size_t) + count_of_codes * (sizeof(char) + sizeof(size_t));
    return {(length == 0 ? 0 : tree.decode(*in, out)), length, additional};
}

}