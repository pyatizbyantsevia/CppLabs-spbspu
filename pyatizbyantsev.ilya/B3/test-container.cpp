#include <boost/test/unit_test.hpp>

#include "container.hpp"

BOOST_AUTO_TEST_SUITE(test_factorial)

BOOST_AUTO_TEST_CASE(correct_values)
{
  pyatizbyantsev::Container container;
  std::vector< unsigned long > vector({1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800});
  BOOST_CHECK_EQUAL_COLLECTIONS(container.begin(), container.end(), vector.begin(), vector.end());
}

BOOST_AUTO_TEST_SUITE_END()
