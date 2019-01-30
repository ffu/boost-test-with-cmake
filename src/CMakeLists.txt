# make a library so unit test can have linker access
add_library(Myprojectlib Foo.cpp Bar.cpp)
add_executable(demo main.cpp)
target_link_libraries(demo Myprojectlib)

set_property(TARGET demo PROPERTY CXX_STANDARD 11)
set_property(TARGET Myprojectlib PROPERTY CXX_STANDARD 11)
