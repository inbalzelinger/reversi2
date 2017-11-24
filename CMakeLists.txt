cmake_minimum_required(VERSION 3.8)
project(untitled2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h GameLevel.cpp GameLevel.h Player.cpp Player.h Point.cpp Point.h ConsolePlayer.cpp ConsolePlayer.h Logic.cpp Logic.h AIPlayer.cpp AIPlayer.h ConsoleLogic.cpp ConsoleLogic.h )
add_executable(untitled2 ${SOURCE_FILES})