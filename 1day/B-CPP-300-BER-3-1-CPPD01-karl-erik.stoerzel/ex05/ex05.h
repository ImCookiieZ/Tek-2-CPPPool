/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** ex05.h
*/

#ifndef PSU_NAVY_2019_EX05_H

#define PSU_NAVY_2019_EX05_H

#endif //PSU_NAVY_2019_EX05_H

#include <stdint.h>

typedef union struct_one {
    int16_t foo;
    int16_t bar;
} s1;

typedef struct struct_two {
    int16_t foo;
    s1 bar;
} s2;

typedef union struct_three {
    int32_t bar;
    s2 foo;
} foo_t;