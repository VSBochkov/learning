cmake_minimum_required(VERSION 2.8)

project(test)

set(SRC_FILES	main.cpp
				data.cpp
)
set(CMAKE_FLAGS_CXX	"${CMAKE_FLAGS_CXX} -std=C++0x -Wall -pedantic")

include_directories(library)

add_executable(test ${SRC_FILES})

add_subdirectory(library)
target_link_libraries(test	data_library)

