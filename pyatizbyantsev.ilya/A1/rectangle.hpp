#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double valueHeight, double valueWidth, const point_t& valuePos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newPos) override;
  void move(double abscissa, double ordinate) override;

private:
  double height_;
  double width_;
  point_t pos_;
};

#endif
