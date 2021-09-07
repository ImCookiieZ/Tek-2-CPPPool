cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel)

set(CMAKE_CXX_STANDARD 14)

file (GLOB lib
        "*/*.cpp")
file (GLOB libh
        "*/*.hpp")
add_executable(B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel general.cpp ${lib} ${libh} ex05/SantaClaus.hpp main_base.cpp)