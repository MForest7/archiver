#include <doctest.h>
#include <limits.h>
#include <huffman.hpp>
#include <sstream>
#include <algorithm>
#include <map>
#include <exception>
#include <iostream>

using std::size_t;
using std::map;
using std::pair;
using std::string;
using std::stringstream;

using namespace huffman;

void test_encode_decode(const HuffmanTree& tree, string text) {
	stringstream in(text);
	stringstream out;
	stringstream res;

	size_t length = text.size();
	out.write((char*)&length, sizeof(size_t));

	tree.encode(in, out);
	tree.decode(out, res);

	CHECK(in.str() == res.str());
}

TEST_SUITE("test huffman tree") {
	TEST_CASE("only letters") {
		map <char, size_t> amount;
		amount['a'] = 10;
		amount['b'] = 2;
		amount['c'] = 6;
		amount['d'] = 2;
		amount['e'] = 15;
		amount['f'] = 3;

		SUBCASE("simple test") {
			SUBCASE("#1") {
				test_encode_decode(HuffmanTree(amount), "abcdef");
			}

			SUBCASE("#2") {
				test_encode_decode(HuffmanTree(amount), "aaaaaaaaaaaaaaaaaaaaaa");
			}

			SUBCASE("#3") {
				test_encode_decode(HuffmanTree(amount), "abababaaaaabababa");
			}
		}

		SUBCASE("large test") {
			const size_t BLOCK_LENGTH = 1e5;

			string text;
			for (pair <char, size_t> entry : amount) {
				char c = entry.first;
				text.append(BLOCK_LENGTH, c);
			}

			test_encode_decode(HuffmanTree(amount), text);
		}
	}

	TEST_CASE("random characters") {
		map <char, size_t> amount;
		for (char c = CHAR_MIN; c < CHAR_MAX; c++)
			amount[c] = 1;

		SUBCASE("simple test") {
			SUBCASE("#1") {
				string text = {13, 52, -12, 32, 95, 42, 122, -68};
				test_encode_decode(HuffmanTree(amount), text);
			}
		}
	}

	TEST_CASE("fail") {
		SUBCASE("no code") {
			map <char, size_t> amount;
			CHECK_THROWS_AS(test_encode_decode(HuffmanTree(amount), "abc"), std::logic_error);
		}

		SUBCASE("unknown char") {
			map <char, size_t> amount;
			amount['a'] = 1;
			amount['c'] = 1;
			CHECK_THROWS_AS(test_encode_decode(HuffmanTree(amount), "abc"), std::logic_error);
		}
	}
}