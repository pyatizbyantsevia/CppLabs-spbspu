#include "test-functions.hpp"

#include <boost/test/unit_test.hpp>

using UniqueShp = std::unique_ptr< pyatizbyantsev::Shape >;
const double EPSILON = 0.001;

pyatizbyantsev::Rectangle pyatizbyantsev::makeRectangle()
{
  return Rectangle(1, 3, {3, 7});
}

pyatizbyantsev::Circle pyatizbyantsev::makeCircle()
{
  return Circle(9, {1, 1});
}

pyatizbyantsev::CompositeShape pyatizbyantsev::makeCompositeShape()
{
  UniqueShp rectangle = std::make_unique< pyatizbyantsev::Rectangle >(makeRectangle());
  UniqueShp circle = std::make_unique< pyatizbyantsev::Circle >(makeCircle());

  return UniqueShp(std::make_unique< CompositeShape >(CompositeShape(std::move(circle), std::move(rectangle))));;
}

void pyatizbyantsev::testMoveToPoint(Shape& shape, const point_t& pos)
{
  rectangle_t r1 = shape.getFrameRect();
  shape.move(pos);
  rectangle_t r2 = shape.getFrameRect();

  BOOST_CHECK_CLOSE_FRACTION(r1.width, r2.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(r1.height, r2.height, EPSILON);
}

void pyatizbyantsev::testScale(Shape& shape, double scaleCoefficient)
{
  double predArea = shape.getArea();
  shape.scale(scaleCoefficient);
  double postArea = shape.getArea();

  BOOST_CHECK_CLOSE_FRACTION(scaleCoefficient * scaleCoefficient * predArea, postArea, EPSILON);
}

void pyatizbyantsev::testInvalidScale(Shape& shape, double scaleCoefficient)
{
  shape.scale(-scaleCoefficient);
}
