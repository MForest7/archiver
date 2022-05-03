#include <huffman.hpp>
#include <algorithm>

namespace huffman {

HuffmanTree::HuffmanTreeNode::HuffmanTreeNode(char c, size_t amount) {
    value = c;
    weight = amount;
    terminated = true;
}

HuffmanTree::HuffmanTreeNode::HuffmanTreeNode(HuffmanTree::HuffmanTreeNode* left, HuffmanTree::HuffmanTreeNode* right) {
    terminated = false;
    weight = left->weight + right->weight;
    next_nodes = {left, right};
}

HuffmanTree::HuffmanTreeNode::HuffmanTreeNode(const HuffmanTree::HuffmanTreeNode& other) {
	terminated = other.terminated;
	weight = other.weight;
	value = other.value;

	if (!terminated) {
		for (HuffmanTree::HuffmanTreeNode* ptr : other.next_nodes)
			next_nodes.push_back(new HuffmanTreeNode(*ptr));
	}
}

HuffmanTree::HuffmanTreeNode::~HuffmanTreeNode() {
	if (terminated)
		return;
	for (HuffmanTree::HuffmanTreeNode* ptr : next_nodes)
		delete ptr;
}

void HuffmanTree::HuffmanTreeNode::swap(HuffmanTree::HuffmanTreeNode& other) {
	std::swap(terminated, other.terminated);
	std::swap(weight, other.weight);
	std::swap(value, other.value);
	std::swap(next_nodes, other.next_nodes);
}

HuffmanTree::HuffmanTreeNode& HuffmanTree::HuffmanTreeNode::operator=(const HuffmanTree::HuffmanTreeNode& other) {
	if (this == &other)
		return *this;

	HuffmanTreeNode tmp(other);
	swap(tmp);
	return *this;
}

void HuffmanTree::HuffmanTreeNode::get_keys(map <char, vector<bool>> &key, vector <bool> trace) const {
    if (terminated) {
        key[value] = trace;
        return;
    }

    trace.push_back(0);
    next_nodes[0]->get_keys(key, trace);
    trace.back() = 1;
    next_nodes[1]->get_keys(key, trace);
    trace.pop_back();
}


bool HuffmanTree::compare::operator()(const HuffmanTreeNode* a, const HuffmanTreeNode* b) {
    return (a->weight > b->weight);
}


HuffmanTree::HuffmanTree() : root(NULL) {}

HuffmanTree::~HuffmanTree() {
	delete root;
}

HuffmanTree::HuffmanTree(const HuffmanTree& other) {
	root = new HuffmanTreeNode(*other.root);
}

HuffmanTree& HuffmanTree::operator=(const HuffmanTree& other) {
    root = NULL;

	if (this == &other)
		return *this;

	delete root;
	if (other.root != NULL)
		root = new HuffmanTreeNode(*other.root);
	else
		root = NULL;
	return *this;
}

HuffmanTree::HuffmanTree(map <char, size_t> amount) {
    root = NULL;

    if (amount.empty())
        return;

    priority_queue <HuffmanTreeNode*, vector <HuffmanTreeNode*>, compare> roots;
    for (pair <char, size_t> entry : amount) {
        char key = entry.first;
        size_t number = entry.second;
        roots.push(new HuffmanTreeNode(key, number));
    }

    while (roots.size() > 1) {
        HuffmanTreeNode* left = roots.top();
        roots.pop();
        HuffmanTreeNode* right = roots.top();
        roots.pop();

        HuffmanTreeNode* united = new HuffmanTreeNode(left, right);
        roots.push(united);
    }

    root = roots.top();
}

size_t HuffmanTree::encode(istream& in, ostream& out) const {
	if (root == NULL)
		throw std::logic_error("Tree is uninitialized");

    map <char, vector <bool>> keys;
    root->get_keys(keys);

    BoolOutputBuffer buffer(out);
    size_t size_encoded = 0;
    for (char c; in.get(c); ) {
        if (keys.find(c) == keys.end())
            throw std::logic_error("Unknown char: " + c);

        buffer.append(keys[c]);
        size_encoded += keys[c].size();
    }

    return (size_encoded + SIZE_OF_BYTE - 1) / SIZE_OF_BYTE;
}

size_t HuffmanTree::decode(istream& in, ostream& out) const {
    if (root == NULL)
        throw std::logic_error("Tree is uninitialized");
    
    size_t length;
    in.read((char*)&length, sizeof(size_t));

    BoolInputBuffer buffer(in);
    HuffmanTreeNode* current_node = root;

    size_t size_encoded = 0;
    for (size_t i = 0; i < length; i++) {
        while(!current_node->terminated) {
            bool next_bit = buffer.read();
            size_encoded++;
            current_node = current_node->next_nodes[next_bit];
        }
        out.put(current_node->value);
        current_node = root;
    }

    return (size_encoded + SIZE_OF_BYTE - 1) / SIZE_OF_BYTE;
}

}