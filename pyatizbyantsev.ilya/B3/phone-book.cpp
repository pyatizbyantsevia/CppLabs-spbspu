#include "phone-book.hpp"

namespace lab = pyatizbyantsev;

lab::PhoneBook::constIterator lab::PhoneBook::begin() const
{
  return data_.begin();
}

lab::PhoneBook::constIterator lab::PhoneBook::end() const
{
  return data_.end();
}

void lab::PhoneBook::add(const Note& note)
{
  return data_.push_back(note);
}

void lab::PhoneBook::insertBefore(constIterator iterator, const Note& note)
{
  data_.insert(iterator, note);
}

void lab::PhoneBook::insertAfter(constIterator iterator, const Note& note)
{
  constIterator tempIterator(iterator);
  tempIterator++;
  if (tempIterator == data_.end())
  {
    data_.push_back(note);
    return;
  }
  data_.insert(tempIterator, note);
}

bool lab::PhoneBook::isEmpty() const
{
  return data_.empty();
}

void lab::PhoneBook::deleteNote(PhoneBook::constIterator iterator)
{
  data_.erase(iterator);
}
