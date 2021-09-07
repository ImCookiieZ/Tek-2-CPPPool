/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** print.c
*/

#include "string.h"
#include <stdio.h>

void print(const string_t *this)
{
    if (this->str) {
        printf("%s", this->str);
        fflush(stdout);
    }
}