cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel C)

set(CMAKE_C_STANDARD 99)

add_executable(B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel main.c string.h
        string_t_init_and_destroy.c assign.c append_s.c at.c clear.c size.c
        compare.c copy.c c_str.c empty.c find.c insert.c to_int.c split_s.c split_c.c print.c join.c substr.c)