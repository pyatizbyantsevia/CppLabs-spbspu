#include <boost/test/unit_test.hpp>

#include "phone-book.hpp"
#include "phone-book-interface.hpp"
#include "note.hpp"

BOOST_AUTO_TEST_SUITE(test_phone_book)


BOOST_AUTO_TEST_CASE(test_iterators)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note1);
  first.add(note2);

  std::list< pyatizbyantsev::Note > second;
  second.push_back(note1);
  second.push_back(note2);

  pyatizbyantsev::PhoneBook::constIterator bookIteratorBegin = first.getPhoneBook().begin();
  std::list< pyatizbyantsev::Note >::const_iterator listIteratorBegin = second.begin();
  BOOST_CHECK(*bookIteratorBegin == *listIteratorBegin);

  pyatizbyantsev::PhoneBook::constIterator bookIteratorEnd = first.getPhoneBook().end();
  std::list< pyatizbyantsev::Note >::const_iterator listIteratorEnd = second.end();
  bookIteratorEnd--;
  listIteratorEnd--;
  BOOST_CHECK(*bookIteratorEnd == *listIteratorEnd);
}

BOOST_AUTO_TEST_CASE(test_is_empty)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note1);
  first.add(note2);
  first.deleteNote("current");
  first.deleteNote("current");

  BOOST_CHECK(first.isEmpty());
}

BOOST_AUTO_TEST_CASE(test_add)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};
  pyatizbyantsev::Note note3 = {"3", "c"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note1);
  first.add(note2);
  first.add(note3);

  std::list< pyatizbyantsev::Note > second;
  second.push_back(note1);
  second.push_back(note2);
  second.push_back(note3);

  pyatizbyantsev::PhoneBook::constIterator firstBegin = first.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator firstEnd = first.getPhoneBook().end();
  BOOST_CHECK_EQUAL_COLLECTIONS(firstBegin, firstEnd, second.begin(), second.end());
}

BOOST_AUTO_TEST_CASE(test_insert_after_if_equals_0)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};
  pyatizbyantsev::Note note3 = {"3", "c"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note1);
  first.add(note2);
  first.add(note3);

  pyatizbyantsev::PhoneBookInterface second;
  second.add(note1);
  second.add(note3);
  second.insertAfter("current", note2);

  pyatizbyantsev::PhoneBook::constIterator firstBegin = first.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator firstEnd = first.getPhoneBook().end();
  pyatizbyantsev::PhoneBook::constIterator secondBegin = second.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator secondEnd = second.getPhoneBook().end();
  BOOST_CHECK_EQUAL_COLLECTIONS(firstBegin, firstEnd, secondBegin, secondEnd);
}

BOOST_AUTO_TEST_CASE(test_insert_after_if_equals_1)
{
  pyatizbyantsev::Note note1 = {"2", "b"};
  pyatizbyantsev::Note note2 = {"3", "c"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note1);
  first.add(note2);

  pyatizbyantsev::PhoneBookInterface second;
  second.add(note1);
  second.insertAfter("current", note2);

  pyatizbyantsev::PhoneBook::constIterator firstBegin = first.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator firstEnd = first.getPhoneBook().end();
  pyatizbyantsev::PhoneBook::constIterator secondBegin = second.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator secondEnd = second.getPhoneBook().end();
  BOOST_CHECK_EQUAL_COLLECTIONS(firstBegin, firstEnd, secondBegin, secondEnd);
}

BOOST_AUTO_TEST_CASE(test_insert_before)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};
  pyatizbyantsev::Note note3 = {"3", "c"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note2);
  first.add(note1);
  first.add(note3);

  pyatizbyantsev::PhoneBookInterface second;
  second.add(note1);
  second.add(note3);
  second.insertBefore("current", note2);

  pyatizbyantsev::PhoneBook::constIterator firstBegin = first.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator firstEnd = first.getPhoneBook().end();
  pyatizbyantsev::PhoneBook::constIterator secondBegin = second.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator secondEnd = second.getPhoneBook().end();
  BOOST_CHECK_EQUAL_COLLECTIONS(firstBegin, firstEnd, secondBegin, secondEnd);
}

BOOST_AUTO_TEST_CASE(test_delete_note)
{
  pyatizbyantsev::Note note1 = {"1", "a"};
  pyatizbyantsev::Note note2 = {"2", "b"};
  pyatizbyantsev::Note note3 = {"3", "c"};

  pyatizbyantsev::PhoneBookInterface first;
  first.add(note2);
  first.add(note3);

  pyatizbyantsev::PhoneBookInterface second;
  second.add(note1);
  second.add(note2);
  second.add(note3);
  second.deleteNote("current");

  pyatizbyantsev::PhoneBook::constIterator firstBegin = first.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator firstEnd = first.getPhoneBook().end();
  pyatizbyantsev::PhoneBook::constIterator secondBegin = second.getPhoneBook().begin();
  pyatizbyantsev::PhoneBook::constIterator secondEnd = second.getPhoneBook().end();
  BOOST_CHECK_EQUAL_COLLECTIONS(firstBegin, firstEnd, secondBegin, secondEnd);
}

BOOST_AUTO_TEST_SUITE_END()
