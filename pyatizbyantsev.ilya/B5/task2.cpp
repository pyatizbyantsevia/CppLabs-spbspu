#include "tasks.hpp"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "shape.hpp"
#include "tools.hpp"

namespace lab = pyatizbyantsev;

void lab::taskTwo(std::istream& in, std::ostream& out)
{
  std::istream_iterator< lab::Shape > firstIterator(in);
  std::istream_iterator< lab::Shape > lastIterator;
  std::vector< Shape > shapes(firstIterator, lastIterator);
  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("Input error");
  }

  int verticesCount = std::accumulate(shapes.begin(), shapes.end(), 0, accumulator);
  int trianglesCount = std::count_if(shapes.begin(), shapes.end(), lab::isTriangle);
  int squaresCount = std::count_if(shapes.begin(), shapes.end(), lab::isSquare);
  int rectanglesCount = std::count_if(shapes.begin(), shapes.end(), lab::isRectangle);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), lab::isPentagon), shapes.end());
  std::vector< lab::Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), getFront);
  std::sort(shapes.begin(), shapes.end());

  out << "Vertices: " << verticesCount;
  out << "\nTriangles: " << trianglesCount;
  out << "\nSquares: " << squaresCount;
  out << "\nRectangles: " << rectanglesCount;
  out << "\nPoints: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< lab::Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< lab::Shape >(out, "\n"));
}
