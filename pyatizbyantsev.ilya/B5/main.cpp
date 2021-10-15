#include <iostream>
#include <stdexcept>

#include "tasks.hpp"

namespace lab = pyatizbyantsev;

int main(int argc, char* argv[])
{
  try
  {
    if ((argc == 2) && (!std::string(argv[1]).compare("1")))
    {
      lab::taskOne(std::cin, std::cout);
      return 0;
    }
    else if ((argc == 2) && (!std::string(argv[1]).compare("2")))
    {
      lab::taskTwo(std::cin, std::cout);
      return 0;
    }
    else
    {
      throw std::invalid_argument("Invalid task number");
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
}
