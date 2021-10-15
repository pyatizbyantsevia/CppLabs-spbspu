#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(circle_test)

BOOST_AUTO_TEST_CASE(test_invalid_scale)
{
  pyatizbyantsev::Circle circle = pyatizbyantsev::makeCircle();
  pyatizbyantsev::testInvalidScale(circle, -2);
}

BOOST_AUTO_TEST_CASE(test_move_to_point)
{
  pyatizbyantsev::Circle circle = pyatizbyantsev::makeCircle();
  pyatizbyantsev::testMoveToPoint(circle, {1, 2});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  pyatizbyantsev::Circle circle = pyatizbyantsev::makeCircle();
  pyatizbyantsev::testScale(circle, 2);
}

BOOST_AUTO_TEST_SUITE_END();
