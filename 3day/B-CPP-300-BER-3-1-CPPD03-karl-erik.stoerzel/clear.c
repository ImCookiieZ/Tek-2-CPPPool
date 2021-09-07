/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** clear.c
*/

#include "string.h"

void clear(string_t *this)
{
    free(this->str);
    this->str = strdup("");
}