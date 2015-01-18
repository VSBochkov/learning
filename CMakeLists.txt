cmake_minimum_required(VERSION 2.8)

add_executable(test main.cpp data.cpp)

set(CMAKE_FLAGS_CXX "-std=C++0x")
