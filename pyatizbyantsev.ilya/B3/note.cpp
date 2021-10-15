#include "note.hpp"

#include <iostream>

std::ostream& pyatizbyantsev::operator<<(std::ostream& out, const pyatizbyantsev::Note& note)
{
  out << note.number << " " << note.name;
  return out;
}

bool pyatizbyantsev::operator!=(const Note& left, const Note& right)
{
  return !((left.name == right.name) && (left.number == right.number));
}

bool pyatizbyantsev::operator==(const Note& left, const Note& right)
{
  return ((left.name == right.name) && (left.number == right.number));
}
