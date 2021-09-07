cmake_minimum_required(VERSION 3.16)
project(Rush3)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SRC_DIR *.cpp ../*.cpp ../getSystemData/*.cpp ../graphical/ncurses/*.cpp ../../*.cpp)

add_subdirectory(SFGraphing)
add_executable(Rush3 ${SRC_DIR})

target_link_libraries(Rush3 SFGraphing ncurses)