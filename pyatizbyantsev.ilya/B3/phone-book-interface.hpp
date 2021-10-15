#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include "phone-book.hpp"

#include <map>

namespace pyatizbyantsev
{
  class PhoneBookInterface
  {
  public:
    using iteratorType = std::map< std::string, PhoneBook::constIterator >::iterator;
    using constIteratorType = std::map< std::string, PhoneBook::constIterator >::const_iterator;

    PhoneBookInterface();
    void add(const Note& src);
    void store(const std::string& oldMark, const std::string& newMark);
    void insertBefore(const std::string& bookmark, const Note& src);
    void insertAfter(const std::string& bookmark, const Note& src);
    void deleteNote(const std::string& bookmark);
    Note show(const std::string& bookmark) const;
    void move(const std::string& bookmark, const int steps);
    void move(const std::string& bookmark, const std::string step);
    bool contains(const std::string& bookmark) const;
    bool isEmpty() const;
    PhoneBook& getPhoneBook();

  private:
    PhoneBook book_;
    std::map< std::string, PhoneBook::constIterator > bookmarks_;

    void checkBookMark(const std::string& bookmark) const;
  };
}

#endif
