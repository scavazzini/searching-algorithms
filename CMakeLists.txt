cmake_minimum_required(VERSION 3.15)
project(searching_algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(searching_algorithms src/empirical_test.cpp src/linear-search/linearsearch.cpp
        src/binary-search/binarysearch.cpp)
