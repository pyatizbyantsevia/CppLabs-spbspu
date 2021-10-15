#include "tasks.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <memory>

#include "functions.hpp"

void pyatizbyantsev::taskTwo(const char* fileName, std::ostream& out)
{
  std::ifstream input;
  input.open(fileName);
  if (!input.is_open())
  {
    throw std::invalid_argument("Unable to read the file");
  }

  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr< char[] > resultArray  = std::make_unique< char[] >(capacity);

  while (!input.eof())
  {
    input.read(resultArray.get() + size, capacity - size);
    size += input.gcount();

    if (capacity == size)
    {
      capacity *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t i = 0; i < size; ++i)
      {
        temp[i] = resultArray[i];
      }
      std::swap(resultArray, temp);
    }
  }
  input.close();
  std::vector< char > vector(resultArray.get(), resultArray.get() + size);
  for (size_t i = 0; i < size; i++)
  {
    out << vector[i];
  }
}
