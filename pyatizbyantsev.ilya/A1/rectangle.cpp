#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double valueHeight, const double valueWidth, const point_t& valuePos):
  height_(valueHeight),
  width_(valueWidth),
  pos_(valuePos)
{
  assert(valueHeight > 0 && valueWidth > 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return{width_, height_, pos_};
}

void Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void Rectangle::move(const double abscissa, const double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}
