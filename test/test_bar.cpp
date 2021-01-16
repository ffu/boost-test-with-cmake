// BOOST_TEST_DYN_LINK can be a target compile definition
// #define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Bar.h"

// Test suite needed if building one test module over multiple cpp files.
// Not needed if using ctest and building separate modules per cpp file.

BOOST_AUTO_TEST_SUITE(testsuitebar)

BOOST_AUTO_TEST_CASE(constructor_test) {
    Bar b;
    BOOST_CHECK_EQUAL(b.x(), 42);
    BOOST_CHECK_EQUAL(b.y(), 43);
}

BOOST_AUTO_TEST_SUITE_END()
