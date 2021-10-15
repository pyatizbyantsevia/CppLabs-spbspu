#include <boost/test/unit_test.hpp>

#include <sstream>

#include "point.hpp"

BOOST_AUTO_TEST_SUITE(test_point)

BOOST_AUTO_TEST_CASE(correct_input)
{
  pyatizbyantsev::Point point;
  std::istringstream iss("(1;3)");
  iss >> point;
  BOOST_CHECK_EQUAL(point.x, 1);
  BOOST_CHECK_EQUAL(point.y, 3);
}

BOOST_AUTO_TEST_CASE(correct_output)
{
  pyatizbyantsev::Point point{1, 3};
  std::string string = "(1; 3)";
  std::ostringstream oss;
  oss << point;
  BOOST_CHECK_EQUAL(string, oss.str());
}

BOOST_AUTO_TEST_SUITE_END()
