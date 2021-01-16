// BOOST_TEST_DYN_LINK set as a target compile definition
// #define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Foo.h"

// Test suite needed if building one test module over multiple cpp files.
// Not needed if using ctest and building separate modules per cpp file.

BOOST_AUTO_TEST_SUITE(testsuitefoo)

BOOST_AUTO_TEST_CASE(constructor_test) {
    Foo f;
    BOOST_CHECK_EQUAL(f.x(), 42);

    Foo f2{24};
    BOOST_REQUIRE_EQUAL(f2.x(), 24);
}

BOOST_AUTO_TEST_SUITE_END()
