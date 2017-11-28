cmake_minimum_required(VERSION 3.8)
project(ReversiTests)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES Point.cpp Point.h )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master)
include_directories(lib/googletest-master)

set(TEST_FILES tests/test_point.cpp )

add_executable(Reversi2 ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)
#add_executable(Reversi2 ${SOURCE_FILES} main.cpp)
target_link_libraries(Reversi2 gtest gtest_main pthread)
add_test(Tests Tests)