#include "data-struct.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

namespace lab = pyatizbyantsev;

int lab::getKey(std::string& str, std::istream& in)
{
  std::string temp;
  int key = 0;
  std::string::iterator tempIterator = str.begin();
  bool isNegative = 0;

  if (*tempIterator == ' ')
  {
    str.erase(str.begin());
  }
  if (*tempIterator == '-')
  {
    str.erase(str.begin());
    isNegative = 1;
  }
  if (str.size() == 1)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  if (tempIterator == str.end())
  {
    in.setstate(std::ios::failbit);
    return 0;
  }

  tempIterator++;
  if (*tempIterator != ',')
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  temp = *str.begin();
  str.erase(str.begin(), ++tempIterator);

  try
  {
    key = std::stoi(temp);
    if (isNegative)
    {
      key *= -1;
    }
  }
  catch (std::exception&)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }

  if (std::abs(key) > 5)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  return key;
}

std::istream& lab::operator>>(std::istream& in, lab::DataStruct& dataStruct)
{
  std::string string;
  std::getline(in, string);

  int key1 = getKey(string, in);
  int key2 = getKey(string, in);

  std::string str = string;
  if (str.empty())
  {
    in.setstate(std::ios::failbit);
  }
  if (!in.fail())
  {
    dataStruct = { key1, key2, str };
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const lab::DataStruct& dataStruct)
{
  out << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
  return out;
}
