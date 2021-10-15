#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace pyatizbyantsev
{
  class Container
  {
  public:
    class Iterator;
    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;

    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned long >
    {
    public:
      using value_type = unsigned long;

      bool operator==(const Iterator& rhs) const;
      bool operator!=(const Iterator& rhs) const;
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      const value_type* operator->() const;
      const value_type& operator*() const;

    private:
      static constexpr unsigned MAX_NUM = 10;
      friend Iterator Container::begin() const noexcept;
      friend Iterator Container::end() const noexcept;
      Iterator(value_type value, value_type index);
      value_type value_;
      value_type index_;
    };
  };
}

#endif
