/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** all_classes.h
*/

#include "object.h"

#ifndef B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_ALL_CLASSES_H

#define B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_ALL_CLASSES_H

typedef struct
{
    Class   base;
    int     x;
} IntClass;

typedef struct
{
    Class   base;
    int     c;
} CharClass;

typedef struct
{
    Class   base;
    float     x;
} FloatClass;

typedef struct
{
    Class base;
    char *str;
} StringClass;

extern const Class   *String;

#endif //B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_ALL_CLASSES_H
