### unless targes are imorted global, must find package for every subdir

### With targets, only unit_test_framework needed. CMake figures out
### all other dependencies

find_package (Boost REQUIRED COMPONENTS unit_test_framework)

set(test_sources
    test_foo.cpp
    test_bar.cpp
)

### for each source: build an executable, register it as a test
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
