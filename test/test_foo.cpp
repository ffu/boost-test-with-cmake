#define BOOST_TEST_MODULE MyCMakeTest
#include <boost/test/unit_test.hpp>

#include "Foo.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    Foo f;
    BOOST_CHECK_EQUAL(f.x(), 42);

    Foo f2{24};
    BOOST_REQUIRE_EQUAL(f2.x(), 24);
}
