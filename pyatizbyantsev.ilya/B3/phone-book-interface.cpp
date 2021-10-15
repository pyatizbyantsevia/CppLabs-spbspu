#include "phone-book-interface.hpp"

#include <map>
#include <string>
#include <memory>
#include <stdexcept>

#include "phone-book.hpp"
#include "note.hpp"

pyatizbyantsev::PhoneBookInterface::PhoneBookInterface():
  book_(PhoneBook()),
  bookmarks_({ std::make_pair("current", book_.begin()) })
{
}

void pyatizbyantsev::PhoneBookInterface::add(const Note& src)
{
  book_.add(src);
  if (bookmarks_.size() == 1)
  {
    bookmarks_.at({"current"}) = book_.begin();
  }
}

void pyatizbyantsev::PhoneBookInterface::store(const std::string& bookmark, const std::string& newBookmark)
{
  iteratorType it = bookmarks_.find(bookmark);
  bookmarks_.insert(std::make_pair(newBookmark, it->second));
}

void pyatizbyantsev::PhoneBookInterface::insertBefore(const std::string& bookmark, const Note& note)
{
  if (bookmark == "current" && book_.isEmpty())
  {
    add(note);
    return;
  }
  iteratorType it = bookmarks_.find(bookmark);
  book_.insertBefore(it->second, note);
}

void pyatizbyantsev::PhoneBookInterface::insertAfter(const std::string& bookmark, const Note& note)
{
  if (bookmark == "current" && book_.isEmpty())
  {
    add(note);
    return;
  }
  iteratorType it = bookmarks_.find(bookmark);
  book_.insertAfter(it->second, note);
}

void pyatizbyantsev::PhoneBookInterface::deleteNote(const std::string& bookmark)
{
  iteratorType it = bookmarks_.find(bookmark);
  auto tempIt = it->second;
  iteratorType current = bookmarks_.begin();
  while (current != bookmarks_.end())
  {
    if (current->second == tempIt)
    {
      if (std::next(current->second) == book_.end())
      {
        current->second = book_.begin();
      }
      else
      {
        ++current->second;
      }
    }
    current++;
  }
  book_.deleteNote(tempIt);
}

pyatizbyantsev::Note pyatizbyantsev::PhoneBookInterface::show(const std::string& bookmark) const
{
  checkBookMark(bookmark);
  if (book_.isEmpty())
  {
    throw std::invalid_argument("<EMPTY>");
  }
  constIteratorType it = bookmarks_.find(bookmark);
  return *it->second;
}

void pyatizbyantsev::PhoneBookInterface::move(const std::string& bookmark, int steps)
{
  iteratorType it = bookmarks_.find(bookmark);
  int size = 0;
  if (steps > 0)
  {
    size = std::distance(it->second, book_.end());
    if (steps >= size)
    {
      it->second = std::prev(book_.end());
      return;
    }
  }
  else
  {
    size = std::distance(book_.begin(), it->second);
    if (std::abs(steps) >= size)
    {
      it->second = book_.begin();
      return;
    }
  }
  std::advance(it->second, steps);
}

void pyatizbyantsev::PhoneBookInterface::move(const std::string& bookmark, const std::string step)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (step == "first")
  {
    it->second = book_.begin();
  }
  else if (step == "last")
  {
    if (book_.isEmpty())
    {
      it->second = book_.end();
    }
    else
    {
      it->second = std::prev(book_.end());
    }
  }
}

bool pyatizbyantsev::PhoneBookInterface::contains(const std::string& bookmark) const
{
  return (bookmarks_.find(bookmark) != bookmarks_.end());
}

bool pyatizbyantsev::PhoneBookInterface::isEmpty() const
{
  return (book_.isEmpty());
}

void pyatizbyantsev::PhoneBookInterface::checkBookMark(const std::string& name) const
{
  if (bookmarks_.find(name) == bookmarks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
}

pyatizbyantsev::PhoneBook& pyatizbyantsev::PhoneBookInterface::getPhoneBook()
{
  return this->book_;
}
