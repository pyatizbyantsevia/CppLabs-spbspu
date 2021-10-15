#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace pyatizbyantsev
{
  template< typename T >
  struct strategyIndex
  {
    using iterator = size_t;
    using container = std::vector< T >;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& container)
    {
      return container.size();
    }

    static T& get(container& data, iterator& index)
    {
      return data[index];
    }
  };

  template< typename T >
  struct strategyAt
  {
    using iterator = size_t;
    using container = std::vector< T >;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& data)
    {
      return data.size();
    }

    static T& get(container& data, iterator& index)
    {
      return data.at(index);
    }
  };

  template< typename T >
  struct strategyIterator
  {
    using iterator = typename std::forward_list< T >::iterator;
    using container = std::forward_list< T >;

    static iterator begin(container& data)
    {
      return data.begin();
    }

    static iterator end(container& data)
    {
      return data.end();
    }

    static T& get(container&, iterator& index)
    {
      return *index;
    }
  };
}

#endif
