cmake_minimum_required(VERSION 3.0)
project(TestProject)

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files
add_library(test_lib test.cpp)
add_executable(test_main main.cpp)

# Link the test executable with Google Test
target_link_libraries(test_main ${GTEST_BOTH_LIBRARIES} test_lib)
