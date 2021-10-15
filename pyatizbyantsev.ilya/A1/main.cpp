#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

void printCoordinatesFigure(const Shape* figure)
{
    std::cout << "Now the figure is located (" << figure->getFrameRect().pos.x
              << ", " << figure->getFrameRect().pos.y << ")\n";
}

int main()
{
  std::cout << "Rectangle test:\n";
  point_t posRectangle = {2.2, 8};

  Shape* figureRectangle = new Rectangle(6, 8, posRectangle);
  printCoordinatesFigure(figureRectangle);

  figureRectangle->move(6, 9);
  printCoordinatesFigure(figureRectangle);

  std::cout << "Area of rectangle is: " << figureRectangle->getArea() << '\n';

  delete figureRectangle;

  std::cout << "Circle test:\n";
  point_t posCircle = {1.3, 3.7};

  Shape* figureCircle = new Circle(3, posCircle);
  printCoordinatesFigure(figureCircle);

  point_t newPosCircle = {55.55, 66.66};
  figureCircle->move(newPosCircle);
  printCoordinatesFigure(figureCircle);

  std::cout << "Area of circle is: " << figureCircle->getArea() << '\n';

  delete figureCircle;

  return 0;
}
