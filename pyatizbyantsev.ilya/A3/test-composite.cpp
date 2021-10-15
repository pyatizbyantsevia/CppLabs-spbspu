#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(composite_shape_test)

BOOST_AUTO_TEST_CASE(test_invalid_scale)
{
  pyatizbyantsev::CompositeShape compositeShape = pyatizbyantsev::makeCompositeShape();
  pyatizbyantsev::testInvalidScale(compositeShape, -2);
}

BOOST_AUTO_TEST_CASE(test_move_to_point)
{
  pyatizbyantsev::CompositeShape compositeShape = pyatizbyantsev::makeCompositeShape();
  pyatizbyantsev::testMoveToPoint(compositeShape, {1, 2});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  pyatizbyantsev::CompositeShape compositeShape = pyatizbyantsev::makeCompositeShape();
  pyatizbyantsev::testScale(compositeShape, 2);
}

BOOST_AUTO_TEST_SUITE_END();
