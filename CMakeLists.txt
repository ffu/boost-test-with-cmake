cmake_minimum_required(VERSION 2.8)
project(Myprojectname)

add_subdirectory(src)

# once you enable testing subsequent subdirs can add tests
enable_testing()
add_subdirectory(test)


# add tests in test subdir
# add_test(NAME MyTest COMMAND UnitTest)
