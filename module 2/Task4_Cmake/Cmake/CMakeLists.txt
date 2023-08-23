cmake_minimum_required(VERSION 3.12)
project(CMake)

# Add the include directories
include_directories(include)

# Add the executable
add_executable(program src/main.cpp src/print.cpp)

# Add the static library target
add_library(WriteInFile STATIC library/WriteInfile.cpp)

# Link the executable with the static library
target_link_libraries(program PRIVATE WriteInFile)
