#ifndef HUFFMAN_HPP_INCLUDED
#define HUFFMAN_HPP_INCLUDED

#include <boolio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <exception>

using std::size_t;
using std::istream;
using std::ostream;
using std::vector;
using std::pair;
using std::map;
using std::priority_queue;
using std::logic_error;

using namespace boolio;

namespace huffman {

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(map <char, size_t> amount);
    ~HuffmanTree();
    HuffmanTree(const HuffmanTree& other);
    HuffmanTree& operator=(const HuffmanTree& other);

    size_t encode(istream& in, ostream& out) const;

    size_t decode(istream& in, ostream& out) const;

private:
    struct HuffmanTreeNode {
        bool terminated;
        size_t weight;
        char value;
        vector <HuffmanTreeNode*> next_nodes;

        HuffmanTreeNode(char c, size_t amount);
        HuffmanTreeNode(HuffmanTreeNode* left, HuffmanTreeNode* right);
        ~HuffmanTreeNode();
        HuffmanTreeNode(const HuffmanTreeNode& other);

        void swap(HuffmanTreeNode& other);

        HuffmanTreeNode& operator=(const HuffmanTreeNode& other);

        void get_keys(map <char, vector<bool>> &key, vector <bool> trace = vector <bool>()) const;
    };

    struct compare {
        bool operator()(const HuffmanTreeNode* a, const HuffmanTreeNode* b);
    };

    HuffmanTreeNode* root;

    static const size_t SIZE_OF_BYTE = 8;
};

}

#endif // HUFFMAN_HPP_INCLUDED