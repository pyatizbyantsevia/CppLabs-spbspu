#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

#include "point.hpp"

namespace pyatizbyantsev
{
  using Shape = std::vector< Point >;

  bool isTriangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isPentagon(const Shape& shape);

  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  std::istream& operator>>(std::istream& in, Shape& shape);
  bool operator<(const Shape& shp1, const Shape& shp2);
}

#endif
