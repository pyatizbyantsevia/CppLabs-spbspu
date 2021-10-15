#include "shape.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>

#include "tools.hpp"

namespace lab = pyatizbyantsev;

std::ostream& lab::operator<<(std::ostream & out, const Shape & shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

std::istream& lab::operator>>(std::istream& in, Shape& shape)
{
  Shape temp;
  size_t size = 0;
  in >> size;
  if (!in || in.get() != ' ')
  {
    in.setstate(std::ios::failbit);
  }
  std::copy_n(std::istream_iterator< Point >(in), size, std::back_inserter(temp));
  if ((in.fail() && in.eof()) && !temp.empty())
  {
    in.clear();
    in.setstate(std::ios::failbit);
  }
  else
  {
    shape.swap(temp);
  }
  return in;
}

bool lab::operator<(const Shape& shp1, const Shape& shp2)
{
  if (shp1.size() < 5 && shp2.size() < 5)
  {
    if (shp1.size() == 4 && shp2.size() == 4)
    {
      return isSquare(shp1) && !isSquare(shp2);
    }
  }
  return (shp1.size() < shp2.size());
}

bool lab::isSquare(const Shape& shape)
{
  return isRectangle(shape) && isAllSidesEqual(shape);
}

bool lab::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool lab::isRectangle(const Shape& shape)
{
  return shape.size() == 4;
}

bool lab::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}
