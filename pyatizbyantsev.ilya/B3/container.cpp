#include "container.hpp"

#include <cassert>
#include <memory>

namespace lab = pyatizbyantsev;

namespace pyatizbyantsev
{
  constexpr unsigned long factorial(unsigned long number)
  {
    if (number == 1)
    {
      return 1;
    }
    else
    {
      return factorial(number - 1) * number;
    }
  }
}

lab::Container::Iterator::Iterator(unsigned long value, size_t index):
  value_(value),
  index_(index)
{
}

bool lab::Container::Iterator::operator==(const Iterator& it) const
{
  return value_ == it.value_;
}

bool lab::Container::Iterator::operator!=(const Iterator& it) const
{
  return !((*this) == it);
}

lab::Container::Iterator& lab::Container::Iterator::operator++()
{
  assert(index_ != MAX_NUM + 1);
  value_ *= ++index_;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  assert(index_ != MAX_NUM + 1);
  Iterator temp = *this;
  ++(*this);
  return temp;
}

lab::Container::Iterator& lab::Container::Iterator::operator--()
{
  assert(index_ != 1);
  value_ /= index_--;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  assert(index_ != 1);
  Iterator temp = (*this);
  --(*this);
  return temp;
}

const unsigned long* lab::Container::Iterator::operator->() const
{
  return std::addressof(value_);
}

const unsigned long& lab::Container::Iterator::operator*() const
{
  assert(index_ != 0);
  return value_;
}

lab::Container::Iterator lab::Container::begin() const noexcept
{
  return Iterator(factorial(1), 1);
}

lab::Container::Iterator lab::Container::end() const noexcept
{
  return Iterator(factorial(11), 11);
}
