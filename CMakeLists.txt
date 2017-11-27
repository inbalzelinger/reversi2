cmake_minimum_required(VERSION 3.8)
project(untitled2)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googlemock/include)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES Board.cpp Board.h GameLevel.cpp GameLevel.h Player.cpp Player.h Point.cpp Point.h ConsolePlayer.cpp Logic.cpp Logic.h ConsolePlayer.h ConsoleLogic.cpp ConsoleLogic.h AIPlayer.cpp AIPlayer.h Symbol.h)
set(TEST_FILES
        tests/mainTest.cpp)

add_executable(untitled2 ${SOURCE_FILES} main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)