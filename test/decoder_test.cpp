#include <decoder.hpp>
#include <doctest.h>
#include <fstream>
#include <exception>

using std::ifstream;
using std::ofstream;
using std::string;

using namespace archive;

void test_decode(string filename) {
	ifstream in("samples/" + filename + "_compressed");
	Decoder d(in);

	ofstream out("samples/actual.txt");
	d.decode(out);

	in.close();
	out.close();

	ifstream expected("samples/" + filename + ".txt");
	ifstream actual("samples/actual.txt");

	while (true) {
		char expected_char, actual_char;
		CHECK((bool)actual.get(actual_char) == (bool)expected.get(expected_char));

		if (expected.fail() || actual.fail()) break;

		CHECK(actual_char == expected_char);
	}
}

TEST_SUITE("test Encoder") {
	TEST_CASE("simple") {
		SUBCASE("#1") {
			test_decode("abcde");
		}
		SUBCASE("#2") {
			test_decode("strange");
		}
		SUBCASE("#3") {
			test_decode("doctest");
		}
	}
}