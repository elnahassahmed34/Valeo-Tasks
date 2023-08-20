cmake_minimum_required(VERSION 3.12)
project(LoggerExample)

find_package(Boost REQUIRED COMPONENTS log log_setup thread)

add_executable(logger logger.cpp)

target_link_libraries(logger PRIVATE Boost::log Boost::log_setup Boost::thread pthread)
