cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPD14A_karl_erik_stoerzel)

set(CMAKE_CXX_STANDARD 14)

file (GLOB EX01 "ex04/*")

add_executable(B_CPP_300_BER_3_1_CPPD14A_karl_erik_stoerzel main.cpp
        ${EX01})