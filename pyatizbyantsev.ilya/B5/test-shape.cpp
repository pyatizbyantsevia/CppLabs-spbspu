#include <boost/test/unit_test.hpp>

#include <sstream>

#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(test_shape)

BOOST_AUTO_TEST_CASE(correct_input)
{
  pyatizbyantsev::Shape shape;
  std::istringstream iss("3 (1;3) (23;3) (15;8)");
  iss >> shape;
  BOOST_CHECK(shape.size() == 3);
  BOOST_CHECK_EQUAL(shape[0].x, 1);
  BOOST_CHECK_EQUAL(shape[0].y, 3);
  BOOST_CHECK_EQUAL(shape[1].x, 23);
  BOOST_CHECK_EQUAL(shape[1].y, 3);
  BOOST_CHECK_EQUAL(shape[2].x, 15);
  BOOST_CHECK_EQUAL(shape[2].y, 8);
}

BOOST_AUTO_TEST_CASE(correct_output)
{
  pyatizbyantsev::Shape shape = {{1, 3}, {23, 3}, {15, 8}};
  std::string string = "3 (1; 3) (23; 3) (15; 8) ";
  std::ostringstream oss;
  oss << shape;
  BOOST_CHECK_EQUAL(string, oss.str());
}

BOOST_AUTO_TEST_SUITE_END()
