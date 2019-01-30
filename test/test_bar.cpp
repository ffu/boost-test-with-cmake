#include <boost/test/unit_test.hpp>

#include "Bar.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    Bar b;
    BOOST_CHECK_EQUAL(b.x(), 42);
    BOOST_CHECK_EQUAL(b.y(), 43);
}
