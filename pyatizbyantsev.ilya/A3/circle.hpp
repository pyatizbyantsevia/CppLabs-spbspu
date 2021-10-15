#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace pyatizbyantsev
{
  class Circle: public Shape
  {
  public:
    Circle(double valueRadius, const point_t& valuePos);
    Circle(const Circle & src);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    void move(const point_t& newPos) override;
    void move(double abscissa, double ordinate) override;
    std::unique_ptr< Shape > clone() const override;

  private:
    double radius_;
    point_t pos_;

    void doScale(double scaleCoefficient) override;
  };
}

#endif
