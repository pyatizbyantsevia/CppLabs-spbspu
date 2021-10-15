#include "point.hpp"

#include <iostream>

namespace lab = pyatizbyantsev;

std::istream& lab::operator>>(std::istream& in, Point& point)
{
  in >> std::ws;
  if (in.get() != '(')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int x = 0;
  in >> x >> std::ws;

  if (in.get() != ';')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int y = 0;
  in >> y >> std::ws;

  if (in.get() != ')')
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  point = {x, y};
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}
