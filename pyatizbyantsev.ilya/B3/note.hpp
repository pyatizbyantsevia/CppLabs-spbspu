#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>
#include <iosfwd>

namespace pyatizbyantsev
{
  struct Note
  {
    std::string number;
    std::string name;
  };
  std::ostream& operator<<(std::ostream& out, const Note& note);
  bool operator!=(const Note& left, const Note& right);
  bool operator==(const Note& left, const Note& right);
}

#endif
