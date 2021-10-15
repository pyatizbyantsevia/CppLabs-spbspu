#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = pyatizbyantsev;

namespace pyatizbyantsev
{
  void printCoordinatesFigure(const lab::Shape& figure)
  {
    std::cout << figure.getName() << " is located (" << lab::getX(figure) << ", " << lab::getY(figure) << ")\n";
  }
}

int main()
{
  using shapePtr = std::unique_ptr< lab::Shape >;
  using rectShape = lab::Rectangle;
  using circShape = lab::Circle;
  using composShape = lab::CompositeShape;

  std::cout << "Rectangle test:\n";
  lab::point_t posRectangle = {2.2, 8};

  shapePtr rect(std::make_unique< rectShape >(rectShape(6, 8, posRectangle)));
  printCoordinatesFigure(*rect);

  rect->move(6, 9);
  printCoordinatesFigure(*rect);

  std::cout << "Area of rectangle is: " << rect->getArea() << '\n';

  std::cout << "Circle test:\n";
  lab::point_t posCircle = {1.3, 3.7};

  shapePtr circ(std::make_unique< circShape >(circShape(3, posCircle)));
  printCoordinatesFigure(*circ);

  lab::point_t newPosCircle = {55.55, 66.66};
  circ->move(newPosCircle);
  printCoordinatesFigure(*circ);

  std::cout << "Area of circle is: " << circ->getArea() << '\n';

  std::cout << "Composite Shape test:" << '\n';
  shapePtr composite1(std::make_unique< composShape >(composShape(std::move(rect), std::move(circ))));
  shapePtr composite2(std::make_unique< composShape >(composite1->clone()));
  printCoordinatesFigure(*composite2);

  composite2->move(3, 0);
  printCoordinatesFigure(*composite2);
  std::cout << "Area of Composite Shape is: " << composite1->getArea() << "\n";

  composite2->scale(3);
  printCoordinatesFigure(*composite2);
  std::cout << "Area of Composite Shape after scale is: " << composite2->getArea() << "\n";

  return 0;
}
