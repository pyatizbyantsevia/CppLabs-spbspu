#include <iostream>
#include <cstring>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc == 2)
    {
      if (strlen(argv[1]) != 1)
      {
        throw std::invalid_argument("Too many arguments");
      }
      if (atoi(argv[1]) == 1)
      {
        pyatizbyantsev::taskOne(std::cin, std::cout);
      }
      else if (atoi(argv[1]) == 2)
      {
        pyatizbyantsev::taskTwo(std::cout);
      }
      else
      {
        throw std::invalid_argument("Argument must be the task number");
      }
    }
    else
    {
      throw std::invalid_argument("Too many arguments");
    }
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
