#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <list>

#include "note.hpp"

namespace pyatizbyantsev
{
  class PhoneBook
  {
  public:
    using constIterator = std::list< Note >::const_iterator;
    using iterator = std::list< Note >::iterator;

    constIterator begin() const;
    constIterator end() const;
    void add(const Note& note);
    void insertBefore(constIterator iterator, const Note& note);
    void insertAfter(constIterator iterator, const Note& note);
    bool isEmpty() const;
    void deleteNote(constIterator iterator);

  private:
    std::list< Note > data_;
  };
}

#endif
