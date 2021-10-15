#include "tasks.hpp"
#include "functions.hpp"

#include <iostream>
#include <vector>

void pyatizbyantsev::taskThree(std::istream& in, std::ostream& out)
{
  std::vector< int > vector;
  int x = 0;

  while (in >> x)
  {
    if (x == 0)
    {
      break;
    }
    vector.push_back(x);
  }

  if (!in.eof() && in.fail())
  {
    throw std::invalid_argument("Incorrect input");
  }

  if (x != 0)
  {
    throw std::invalid_argument("The last character must be zero");
  }

  if (vector.empty())
  {
    return;
  }

  std::vector< int >::iterator iterator = vector.begin();
  if (vector.back() == 1)
  {
    while (iterator != vector.end())
    {
      if ((*iterator % 2) == 0)
      {
        iterator = vector.erase(iterator);
      }
      else
      {
        iterator++;
      }
    }
  }
  else if (vector.back() == 2)
  {
    while (iterator != vector.end())
    {
      if ((*iterator % 3) == 0)
      {
        iterator = vector.insert(iterator + 1, 3, 1);
        iterator += 2;
      }
      else
      {
        iterator++;
      }
    }
  }
  print< pyatizbyantsev::strategyIndex< int > >(vector, out, " ");
}
