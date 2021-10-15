#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace pyatizbyantsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual std::unique_ptr< Shape > clone() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual std::string getName() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double abscissa, double ordinate) = 0;
    void scale(double scaleCoefficient);

  private:
    virtual void doScale(double scaleCoefficient) = 0;
  };
  double getX(const Shape & src);
  double getY(const Shape & src);
  double getWidth(const Shape & src);
  double getHeight(const Shape & src);

  double getLeft(const Shape & src);
  double getRight(const Shape & src);
  double getTop(const Shape & src);
  double getBottom(const Shape & src);
}

#endif
