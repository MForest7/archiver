#include <encoder.hpp>

namespace archive {

Encoder::Encoder(istream& _in) : in(&_in) {
    length = 0;
    auto pos = in->tellg();

    istream fin(in->rdbuf());

    for (char c; fin.get(c); ) {
        amount[c]++;
        length++;
    }

    in->seekg(pos);
    tree = HuffmanTree(amount);
}

report Encoder::encode(ostream& out) {
    size_t count_of_codes = amount.size();
    out.write((char*)&count_of_codes, sizeof(size_t));

    for (pair <char, size_t> entry : amount) {
        char key = entry.first;
        size_t number = entry.second;
        out.put(key);
        out.write((char*)&number, sizeof(size_t));
    }

    out.write((char*)&length, sizeof(size_t));

    size_t additional = count_of_codes * (sizeof(char) + sizeof(size_t)) + 2 * sizeof(size_t);
    return {length, (length == 0 ? 0 : tree.encode(*in, out)), additional};
}

}