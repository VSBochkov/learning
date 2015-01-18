cmake_minimum_required(VERSION 2.8)

project(data_library)

set(SRC_FILES	data_structs.cpp)

add_library(data_library SHARED ${SRC_FILES})
