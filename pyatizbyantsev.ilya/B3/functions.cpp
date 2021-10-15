#include "functions.hpp"

#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <istream>

std::string pyatizbyantsev::checkName(std::istream& in)
{
  std::string name;
  in >> std::ws;
  std::getline(in, name);
  if ((name.front() != '"') || (name.back() != '"') || (name.size() < 2))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name.pop_back();
  name.erase(0, 1);
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());

  return name;
}

void pyatizbyantsev::checkChar(const char& ch)
{
  if (!std::isalpha(ch) && !std::isdigit(ch) && ch != '-')
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
}

void pyatizbyantsev::checkMarkName(const std::string& markName)
{
  std::for_each(markName.begin(), markName.end(), checkChar);
}

void pyatizbyantsev::checkNumber(const std::string& num)
{
  if (!std::all_of(num.begin(), num.end(), ::isdigit))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
}
