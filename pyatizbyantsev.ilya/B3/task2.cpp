#include "tasks.hpp"

#include <iostream>
#include <algorithm>

#include "container.hpp"

void pyatizbyantsev::taskTwo(std::ostream& out)
{
  pyatizbyantsev::Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< int >(out, " "));
  std::cout << '\n';
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< int >(out, " "));
  std::cout << '\n';
}
