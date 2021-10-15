#include "shape.hpp"
#include <stdexcept>

void pyatizbyantsev::Shape::scale(const double scaleCoefficient)
{
  if (scaleCoefficient <= 0)
  {
    throw (std::invalid_argument("Сoefficient cannot be negative or equal to zero"));
  }
  doScale(scaleCoefficient);
}

double pyatizbyantsev::getWidth(const Shape& src)
{
  return src.getFrameRect().width;
}

double pyatizbyantsev::getHeight(const Shape& src)
{
  return src.getFrameRect().height;
}

double pyatizbyantsev::getX(const Shape& src)
{
  return src.getFrameRect().pos.x;
}

double pyatizbyantsev::getY(const Shape& src)
{
  return src.getFrameRect().pos.y;
}

double pyatizbyantsev::getLeft(const Shape& src)
{
  return (getX(src) - getWidth(src) / 2);
}

double pyatizbyantsev::getRight(const Shape& src)
{
  return (getX(src) + getWidth(src) / 2);
}

double pyatizbyantsev::getTop(const Shape& src)
{
  return (getY(src) + getHeight(src) / 2);
}

double pyatizbyantsev::getBottom(const Shape& src)
{
  return (getY(src) - getHeight(src) / 2);
}
