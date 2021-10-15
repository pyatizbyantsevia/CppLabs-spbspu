#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace pyatizbyantsev
{
  Rectangle makeRectangle();
  Circle makeCircle();
  CompositeShape makeCompositeShape();

  void testMoveToPoint(Shape& shape, const point_t& pos);
  void testScale(Shape& shape, double scaleCoefficient);
  void testInvalidScale(Shape& shape, double scaleCoefficient);
}

#endif
