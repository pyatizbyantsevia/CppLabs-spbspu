#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "data-struct.hpp"
#include "comparator.hpp"

namespace lab = pyatizbyantsev;

int main()
{
  std::istream_iterator< lab::DataStruct > beginstreamIterator(std::cin);
  std::istream_iterator< lab::DataStruct > finishIstreamIterator;
  std::vector< lab::DataStruct > structs(beginstreamIterator, finishIstreamIterator);
  if (!std::cin && !std::cin.eof())
  {
    std::cerr << "Input error" << '\n';
    return 1;
  }
  std::sort(structs.begin(), structs.end(), lab::compare);
  std::ostream_iterator< lab::DataStruct > out(std::cout, "\n");
  std::copy(structs.begin(), structs.end(), out);
}
