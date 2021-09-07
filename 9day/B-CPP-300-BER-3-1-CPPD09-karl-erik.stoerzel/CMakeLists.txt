cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel)

set(CMAKE_CXX_STANDARD 14)

file (GLOB lib
        "*.cpp")

add_executable(B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel ${lib})