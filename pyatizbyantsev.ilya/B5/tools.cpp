#include "tools.hpp"

#include <algorithm>
#include <iostream>
#include <functional>
#include <cmath>

#include "point.hpp"
#include "shape.hpp"

namespace lab = pyatizbyantsev;

bool lab::isAllSidesEqual(const Shape& shp)
{
  std::vector< int > sides;
  std::transform(shp.begin() + 1, shp.end(), shp.begin(), std::back_inserter(sides), getDistanceSquared);

  using std::placeholders::_1;
  int last = getDistanceSquared(shp.front(), shp.back());
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), _1, last));
}

int lab::getDistanceSquared(const Point& first, const Point& second)
{
  int dx = first.x - second.x;
  int dy = first.y - second.y;
  return (std::pow(dx, 2) + std::pow(dy, 2));
}

size_t lab::accumulator(size_t acc, const Shape& shape)
{
  return acc + shape.size();
}

lab::Point lab::getFront(const Shape& shape)
{
  return shape.front();
}
