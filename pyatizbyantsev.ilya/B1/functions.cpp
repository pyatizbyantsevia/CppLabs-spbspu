#include "functions.hpp"

#include <cctype>
#include <cmath>
#include <cstring>

bool pyatizbyantsev::checkSpaces(const char* str)
{
  return (std::strchr(str, ' '));
}

bool pyatizbyantsev::checkNumber(const char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

void pyatizbyantsev::fillRandom(double *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = (rand() % 21) / 10.0 - 1;
  }
}

void pyatizbyantsev::printError(const char* error, std::ostream& out)
{
  out << error << '\n';
}
