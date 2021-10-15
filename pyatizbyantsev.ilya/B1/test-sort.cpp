#include <boost/test/unit_test.hpp>

#include "functions.hpp"

namespace lab = pyatizbyantsev;

BOOST_AUTO_TEST_SUITE(sortings)

BOOST_AUTO_TEST_CASE(at_strategy)
{
  std::vector< int > vectorFirst{4, 1, 2, 3, 7, 5, 10};
  std::vector< int > vectorSecond(vectorFirst);

  std::function< bool(int, int) > cmp = lab::sortMode< int >("ascending");

  lab::sort< lab::strategyAt< int >, int >(vectorFirst, cmp);
  std::sort(vectorSecond.begin(), vectorSecond.end(), cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(vectorFirst.begin(), vectorFirst.end(), vectorSecond.begin(), vectorSecond.end());
}

BOOST_AUTO_TEST_CASE(index_strategy)
{
  std::vector< int > vectorFirst{4, 1, 2, 3, 7, 5, 10};
  std::vector< int > vectorSecond(vectorFirst);

  std::function< bool(int, int) > cmp = lab::sortMode< int >("descending");

  lab::sort< lab::strategyIndex< int >, int >(vectorFirst, cmp);
  std::sort(vectorSecond.begin(), vectorSecond.end(), cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(vectorFirst.begin(), vectorFirst.end(), vectorSecond.begin(), vectorSecond.end());
}

BOOST_AUTO_TEST_CASE(iterator_strategy)
{
  std::forward_list< int > forwardList{4, 1, 2, 3, 7, 5, 10};
  std::vector< int > vector{4, 1, 2, 3, 7, 5, 10};

  std::function< bool(int, int) > cmp = lab::sortMode< int >("ascending");

  lab::sort< lab::strategyIterator< int >, int >(forwardList, cmp);
  std::sort(vector.begin(), vector.end(), cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(forwardList.begin(), forwardList.end(), vector.begin(), vector.end());
}

BOOST_AUTO_TEST_SUITE_END();
