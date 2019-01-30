find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${Myprojectname_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIRS}
    )

add_definitions(-DBOOST_TEST_DYN_LINK)


SET(test_sources
    test_foo.cpp
    test_bar.cpp
)

#for each source: build an executable, register it as a test
FOREACH(test_source ${test_sources})
    GET_FILENAME_COMPONENT(test_name ${test_source} NAME_WE)
    ADD_EXECUTABLE(${test_name} ${test_source})
    TARGET_LINK_LIBRARIES(${test_name}
			  Myprojectlib
			  ${Boost_LIBRARIES}
			  )

    ADD_TEST(NAME ${test_name} COMMAND ${test_name})
    SET_PROPERTY(TARGET ${test_name} PROPERTY CXX_STANDARD 11)

ENDFOREACH(test_source)



#add_executable(UnitTest test_foo.cpp)
#target_link_libraries(UnitTest
#    MyFoo
#    ${Boost_FILESYSTEM_LIBRARY}
#    ${Boost_SYSTEM_LIBRARY}
#    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
#    )


#add_test(NAME MyTest COMMAND UnitTest)
