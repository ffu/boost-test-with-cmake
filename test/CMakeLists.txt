find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

set(test_sources
    test_foo.cpp
    test_bar.cpp
)

#for each source: build an executable, register it as a test
foreach(test_source ${test_sources})
  get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})

    target_compile_definitions(
      ${test_name} PRIVATE
      -DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)
      
    target_include_directories(
      ${test_name} PRIVATE
      ${Boost_INCLUDE_DIRS} 
      ${CMAKE_SOURCE_DIR}/src)
    
    target_link_libraries(
      ${test_name}
      Myprojectlib
      ${Boost_LIBRARIES})

    add_test(NAME ${test_name} COMMAND ${test_name})
    set_target_properties(${test_name} PROPERTIES CXX_STANDARD 11)

endforeach(test_source)


