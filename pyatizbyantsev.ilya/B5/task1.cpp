#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <iterator>
#include <algorithm>

namespace lab = pyatizbyantsev;

void lab::taskOne(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > istreamBegin(in);
  std::istream_iterator< std::string > istreamEnd;
  std::unordered_set< std::string > set(istreamBegin, istreamEnd);
  std::copy(set.begin(), set.end(), std::ostream_iterator< std::string >(out, "\n"));
}
