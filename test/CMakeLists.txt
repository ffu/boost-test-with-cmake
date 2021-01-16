find_package (Boost REQUIRED COMPONENTS unit_test_framework)

#### This section focuses on  using ctest.  Separate, single-file test modules
#### are built with Boost.Test and added to ctest.  The ctest command is used
#### to run all the tests.  This requires more boilerplate here in
#### CMakeLists.txt, but building the test sources are much easier.
#### Separate test suites are no longer needed. BOOST_TEST_MAIN or
#### BOOST_TEST_MODULE can be a compile definition. Therefore, test_module.cpp
#### can be avoided.  Tests can be simply run as ctest or ctest -V.

set(test_sources
    test_foo.cpp
    test_bar.cpp
    )

### for each source: build an executable, register it to ctest
foreach(test_source ${test_sources})
  get_filename_component(test ${test_source} NAME_WE)
  add_executable(${test} ${test_source})

  target_compile_definitions(${test}
    PRIVATE -DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN
    )

### Modern CMake! Just link the targets and CMake figures out the dependencies
### No more fretting about Boost_INCLUDE_DIRS or Boost_LIBRARIES

  target_link_libraries(${test}
    PRIVATE
      Myprojectlib
      Boost::unit_test_framework
    )

    add_test(NAME ${test} COMMAND ${test})
    set_target_properties(${test} PROPERTIES CXX_STANDARD 11)

endforeach(test_source)

### This section creates a single executable and passes organization
### responsibilities to Boost.Test. The executable test_module_foobar
### is created.  Run with $ test_module_foobar.
### See all options with $ test_module_foobar --help

### Note test_module.cpp included, just to get a single BOOST_TEST_MODULE
add_executable(test_module_foobar test_module.cpp ${test_sources})
target_compile_definitions(test_module_foobar
  PRIVATE -DBOOST_TEST_DYN_LINK
  )

target_link_libraries(test_module_foobar
  PRIVATE
    Myprojectlib
    Boost::unit_test_framework
  )

set_target_properties(test_module_foobar PROPERTIES CXX_STANDARD 11)

### For best of both worlds, perhaps a single test could be added to ctest
# add_test(NAME test_module_foobar COMMAND test_module_foobar)
