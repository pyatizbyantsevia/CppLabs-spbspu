#include "composite-shape.hpp"

pyatizbyantsev::CompositeShape::CompositeShape(const pyatizbyantsev::CompositeShape & src):
  size_(src.size_),
  data_(std::make_unique< std::unique_ptr< Shape >[] >(size_))
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i] = src.data_[i]->clone();
  }
}

double pyatizbyantsev::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += data_[i]->getArea();
  }
  return area;
}

pyatizbyantsev::rectangle_t pyatizbyantsev::CompositeShape::getFrameRect() const
{
  double left = getLeft(*data_[0]);
  double right = getRight(*data_[0]);
  double top = getTop(*data_[0]);
  double bottom = getBottom(*data_[0]);

  for (size_t i = 0; i < size_; i++)
  {
    double leftBorder = getLeft(*data_[i]);
    double rightBorder = getRight(*data_[i]);
    double topBorder = getTop(*data_[i]);
    double bottomBorder = getBottom(*data_[i]);

    left = std::min(left, leftBorder);
    right = std::max(right, rightBorder);
    top = std::max(top, topBorder);
    bottom = std::min(bottom, bottomBorder);
  }

  double width = right - left;
  double height = top - bottom;
  point_t pos = {right - width / 2, top - height / 2};

  return {width, height, pos};
}

void pyatizbyantsev::CompositeShape::move(const double abscissa, const double ordinate)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(abscissa, ordinate);
  }
}

void pyatizbyantsev::CompositeShape::move(const pyatizbyantsev::point_t& newPos)
{
  move(newPos.x, newPos.y);
}

std::string pyatizbyantsev::CompositeShape::getName() const
{
  return "Composite Shape";
}

size_t pyatizbyantsev::CompositeShape::getSize() const
{
  return size_;
}

void pyatizbyantsev::CompositeShape::doScale(double scaleCoefficient)
{
  double x = getX(*this);
  double y = getY(*this);
  for (size_t i = 0; i < size_; i++)
  {
    double abscissa = getX(*data_[i]) - x;
    double ordinate = getY(*data_[i]) - y;
    double newX = x + abscissa * scaleCoefficient;
    double newY = y + ordinate * scaleCoefficient;
    data_[i]->move({ newX, newY });
    data_[i]->scale(scaleCoefficient);
  }
}

std::unique_ptr< pyatizbyantsev::Shape > pyatizbyantsev::CompositeShape::clone() const
{
  return std::make_unique< pyatizbyantsev::CompositeShape >(*this);
}
