#include "circle.hpp"
#include <stdexcept>

const double PI = 3.1415926535;

pyatizbyantsev::Circle::Circle(const double valueRadius, const point_t& valuePos):
  radius_(valueRadius),
  pos_(valuePos)
{
  if (radius_ <= 0)
  {
    throw (std::invalid_argument("Parametrs cannot be negative or equal to zero"));
  }
}

pyatizbyantsev::Circle::Circle(const pyatizbyantsev::Circle & src):
  radius_(src.radius_),
  pos_({src.pos_.x, src.pos_.y})
{
}

double pyatizbyantsev::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

pyatizbyantsev::rectangle_t pyatizbyantsev::Circle::getFrameRect() const
{
  return{radius_ * 2, radius_ * 2, pos_};
}

void pyatizbyantsev::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void pyatizbyantsev::Circle::move(const double abscissa, const double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}

void pyatizbyantsev::Circle::doScale(const double scaleCoefficient)
{
  radius_ *= scaleCoefficient;
}

std::string pyatizbyantsev::Circle::getName() const
{
  return "Circle";
}

std::unique_ptr< pyatizbyantsev::Shape > pyatizbyantsev::Circle::clone() const
{
  return std::make_unique< pyatizbyantsev::Circle >(*this);
}
