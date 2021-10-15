#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace pyatizbyantsev
{
  struct Point
  {
    int x;
    int y;
  };
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Point& point);
}

#endif
