cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "*.c" "bonus/*.c")

add_executable(B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel ${lib_dir})
#add_executable(B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel ex06.c list.c
#        new.c int.c)