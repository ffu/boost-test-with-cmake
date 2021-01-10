## CMake 3.5 creates Boost targets, which dramatically helps with modern CMake
cmake_minimum_required(VERSION 3.5)
project(Myprojectname)

add_subdirectory(src)

# once you enable testing subsequent subdirs can add tests
enable_testing()
add_subdirectory(test)
