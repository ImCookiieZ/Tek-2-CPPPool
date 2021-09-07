cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPD01_karl_erik_stoerzel C)

set(CMAKE_C_STANDARD 11)

include_directories(ex01)
include_directories(ex02)
include_directories(ex04)
include_directories(ex05)
include_directories(ex06)

add_executable(B_CPP_300_BER_3_1_CPPD01_karl_erik_stoerzel
        ex00/z.c
        ex01/main.c
        ex01/menger.c
        ex01/menger.h
        ex02/bitmap.h
        ex02/bitmap_header.c
        ex03/pyramid.c
        ex04/bitmap.h
        ex04/bitmap_header.c
        ex04/drawing.c
        ex04/drawing.h
        ex05/ex05.h
        ex06/bitmap.h
        ex06/bitmap_header.c
        ex06/drawing.c
        ex06/drawing.h
        ex06/main.c
        ex06/menger.c
        ex06/menger.h)
