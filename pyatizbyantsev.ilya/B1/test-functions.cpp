#include <boost/test/unit_test.hpp>

#include "functions.hpp"

BOOST_AUTO_TEST_SUITE(functions)

BOOST_AUTO_TEST_CASE(check_spaces)
{
  std::string string("Test message with spaces");
  BOOST_REQUIRE_EQUAL(pyatizbyantsev::checkSpaces(string.c_str()), 1);
}

BOOST_AUTO_TEST_CASE(check_number)
{
  std::string string("Test message without numbers");
  BOOST_REQUIRE_EQUAL(pyatizbyantsev::checkNumber(string.c_str()), 0);
}

BOOST_AUTO_TEST_SUITE_END();
