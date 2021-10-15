#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(rectangle_test)

BOOST_AUTO_TEST_CASE(test_invalid_scale)
{
  pyatizbyantsev::Rectangle rectangle = pyatizbyantsev::makeRectangle();
  pyatizbyantsev::testInvalidScale(rectangle, -2);
}

BOOST_AUTO_TEST_CASE(test_move_to_point)
{
  pyatizbyantsev::Rectangle rectangle = pyatizbyantsev::makeRectangle();
  pyatizbyantsev::testMoveToPoint(rectangle, {1, 2});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  pyatizbyantsev::Rectangle rectangle = pyatizbyantsev::makeRectangle();
  pyatizbyantsev::testScale(rectangle, 2);
}

BOOST_AUTO_TEST_SUITE_END();
