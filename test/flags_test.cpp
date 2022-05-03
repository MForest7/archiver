#include <flags.hpp>
#include <doctest.h>
#include <exception>

using std::string;

using namespace flags;

bool operator==(const flag& a, const flag& b) {
	return (a.name == b.name && a.full_name == b.full_name && a.need_arg == b.need_arg);
}

TEST_SUITE("test FlagsValidator") {
	TEST_CASE("simple") {
		flag a = {"-a", "--apple", false};
		flag p = {"-p", "--pen", true};

		FlagsValidator FLAGS = FlagsValidator({a, p});

		SUBCASE("all correct: known_flag") {
			CHECK(FLAGS.known_flag("-a") == true);
			CHECK(FLAGS.known_flag("--pen") == true);
			CHECK(FLAGS.known_flag("--pineapple") == false);
			CHECK(FLAGS.known_flag("--pineapple") == false);
		}

		SUBCASE("all correct: flag by name") {
			CHECK(FLAGS.get_by_name("-a") == a);
			CHECK(FLAGS.get_by_name("--pen") == p);
		}

		SUBCASE("unknown flag") {
			CHECK_THROWS_AS(FLAGS.get_by_name("--pineapple"), std::logic_error);
		}

		SUBCASE("duplicate flag") {
			CHECK(FLAGS.get_by_name("-a") == a);
			CHECK_THROWS_WITH_AS(FLAGS.get_by_name("--apple"), "Duplicate flag: --apple", std::logic_error);
		}
	}
}