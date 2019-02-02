cmake_minimum_required(VERSION 2.6)

add_subdirectory(test)
 
# Locate GTest
find_package(GTest REQUIRED)
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test/quicksort_test.cc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
