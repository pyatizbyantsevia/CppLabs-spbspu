#ifndef TASKS_HPP
#define TASKS_HPP

#include <iosfwd>

namespace pyatizbyantsev
{
  void taskOne(const char* cmp, std::istream& in, std::ostream& out);
  void taskTwo(const char* fileName, std::ostream& out);
  void taskThree(std::istream& in, std::ostream& out);
  void taskFour(const char* cmp, int size, std::ostream& out);
}

#endif
