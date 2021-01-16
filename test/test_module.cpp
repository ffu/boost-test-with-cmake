// This file only needed to set BOOST_TEST_MODULE in one and only one
// location when running a test module with multiple translation units

// define the testmodule before including the header

#define BOOST_TEST_MODULE MyFoobarTestModule
#include<boost/test/unit_test.hpp>
