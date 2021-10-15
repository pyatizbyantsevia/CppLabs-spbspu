#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace pyatizbyantsev
{
  void checkMarkName(const std::string& markName);
  void checkChar(const char& ch);
  std::string checkName(std::istream& in);
  void checkNumber(const std::string& num);
  bool checkSteps(const std::string& steps);
}

#endif
