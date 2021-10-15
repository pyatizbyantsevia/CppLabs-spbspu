#include <boost/test/unit_test.hpp>

#include <sstream>

#include "data-struct.hpp"

namespace lab = pyatizbyantsev;

BOOST_AUTO_TEST_SUITE(test_data_struct)

  BOOST_AUTO_TEST_CASE(test_correct_input)
  {
    lab::DataStruct dataStruct;
    std::stringstream in("1, 2,test");
    in >> dataStruct;
    BOOST_CHECK_EQUAL(dataStruct.key1, 1);
    BOOST_CHECK_EQUAL(dataStruct.key2, 2);
    BOOST_CHECK_EQUAL(dataStruct.str, "test");
  }

  BOOST_AUTO_TEST_CASE(test_incorrect_input)
  {
    lab::DataStruct dataStruct;
    std::stringstream in("6, 2,test");
    in >> dataStruct;
    BOOST_CHECK(in.fail());
  }

  BOOST_AUTO_TEST_CASE(test_correct_output)
  {
    lab::DataStruct dataStruct{1, -2, "str"};
    std::string string("1, -2, str");
    std::ostringstream ostringstream;
    ostringstream << dataStruct;
    BOOST_CHECK_EQUAL(ostringstream.str(), string);
  }

BOOST_AUTO_TEST_SUITE_END()
