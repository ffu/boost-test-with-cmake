# make a library so unit test can have linker access
add_library(Myprojectlib STATIC Foo.cpp Bar.cpp)

# the header files are also in this directory.  Include it so unit tests
# in tests/ directory can have access.  Don't have to worry about
# install tree because library only used for internal unit tests

target_include_directories(Myprojectlib PUBLIC .)

# an executable example that uses Myprojectlib
add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE Myprojectlib)

# Too many ways to enable c++ 11
# https://crascit.com/2015/03/28/enabling-cxx11-in-cmake/

set_property(TARGET demo PROPERTY CXX_STANDARD 11)
set_property(TARGET Myprojectlib PROPERTY CXX_STANDARD 11)
