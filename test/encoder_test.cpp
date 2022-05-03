#include <encoder.hpp>
#include <doctest.h>
#include <fstream>
#include <exception>

using std::ifstream;
using std::ofstream;
using std::string;

using namespace archive;

void test_encode(string filename) {
	ifstream in("samples/" + filename + ".txt");
	Encoder e(in);

	ofstream out("samples/actual");
	e.encode(out);

	in.close();
	out.close();

	ifstream expected("samples/" + filename + "_compressed");
	ifstream actual("samples/actual");

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
			test_encode("abcde");
		}
		SUBCASE("#2") {
			test_encode("strange");
		}
		SUBCASE("#3") {
			test_encode("doctest");
		}
	}
}