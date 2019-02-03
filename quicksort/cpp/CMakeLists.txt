cmake_minimum_required(VERSION 2.6)

add_subdirectory(test)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link executables with what we want to test and the GTest and pthread library
add_executable(runQuicksortTests test/quicksort_test.cc)
add_executable(runMergeSortTests test/merge_sort_test.cc)
target_link_libraries(runQuicksortTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runMergeSortTests ${GTEST_LIBRARIES} pthread)
