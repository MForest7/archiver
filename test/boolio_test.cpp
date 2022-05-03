#include <doctest.h>
#include <boolio.hpp>
#include <sstream>

using std::stringstream;
using std::string;

using namespace boolio;

void test_input_one_byte(unsigned char value) {
	const size_t SIZE_OF_BYTE = 8;

	stringstream in;
	in << value;

	BoolInputBuffer b(in);
	for (size_t i = 0; i < SIZE_OF_BYTE; i++)
		value ^= ((unsigned char)b.read() << i);

	CHECK(value == 0);
}

void test_input_str(string str) {
	const size_t SIZE_OF_BYTE = 8;

	stringstream in;
	in << str;

	BoolInputBuffer b(in);

	for (unsigned char value : str) {
		for (size_t i = 0; i < SIZE_OF_BYTE; i++)
			value ^= ((unsigned char)b.read() << i);
		CHECK(value == 0);
	}
}

void test_output_one_byte(unsigned char value) {
	const size_t SIZE_OF_BYTE = 8;

	stringstream out;

	BoolOutputBuffer b(out);
	for (size_t i = 0; i < SIZE_OF_BYTE; i++)
		b.write((value & (1 << i)) ? 1 : 0);

	char written;
	out.get(written);
	CHECK((unsigned char)written == value);
}

void test_output_str(string str) {
	const size_t SIZE_OF_BYTE = 8;

	stringstream out;

	BoolOutputBuffer b(out);
	for (unsigned char value : str) {
		for (size_t i = 0; i < SIZE_OF_BYTE; i++)
			b.write((value & (1 << i)) ? 1 : 0);
	}

	for (char value : str) {
		char written;
		out.get(written);
		CHECK(written == value);
	}
}

TEST_SUITE("test BoolInputBuffer") {
	TEST_CASE("one byte") {
		SUBCASE("#1") {
			test_input_one_byte(16);
		}
		SUBCASE("#2") {
			test_input_one_byte(0);
		}
		SUBCASE("#3") {
			test_input_one_byte(255);
		}
	}

	TEST_CASE("more bytes") {
		SUBCASE("#1") {
			test_input_str("qwerty");
		}
		SUBCASE("#2") {
			test_input_str("3243431212");
		}
		SUBCASE("#3") {
			test_input_str("$(@#(#");
		}
	}
}

TEST_SUITE("test BoolOutputBuffer") {
	TEST_CASE("one byte") {
		SUBCASE("#1") {
			test_output_one_byte(16);
		}
		SUBCASE("#2") {
			test_output_one_byte(0);
		}
		SUBCASE("#3") {
			test_output_one_byte(255);
		}
	}

	TEST_CASE("more bytes") {
		SUBCASE("#1") {
			test_output_str("qwerty");
		}
		SUBCASE("#2") {
			test_output_str("3243431212");
		}
		SUBCASE("#3") {
			test_output_str("$(@#(#");
		}
	}
}