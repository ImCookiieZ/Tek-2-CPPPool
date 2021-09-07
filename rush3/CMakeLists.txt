cmake_minimum_required(VERSION 3.16)
project(rush3)

set(CMAKE_CXX_STANDARD 14)

link_libraries(ncurses)

add_executable(rush3 main.cpp src/getSystemData/SystemGetter.cpp src/CpuMhzInfo.cpp src/CpuMhzInfo.hpp
        src/getSystemData/SystemGetter.hpp src/User.cpp src/User.hpp src/graphical/ncurses/mainWindow.cpp src/graphical/ncurses/mainWindow.hpp src/Displays.cpp src/Displays.hpp src/CpuPercentage.cpp src/CpuPercentage.hpp src/RamInfos.cpp src/RamInfos.hpp src/SwapInfos.cpp src/SwapInfos.hpp)