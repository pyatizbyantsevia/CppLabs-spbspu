#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "shape.hpp"
#include "point.hpp"

namespace pyatizbyantsev
{
  bool isAllSidesEqual(const Shape& shp);
  int getDistanceSquared(const Point& p1, const Point& p2);
  size_t accumulator(size_t acc, const Shape& shape);
  Point getFront(const Shape& shape);
}

#endif
