/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** empty.c
*/

#include "string.h"

int empty(const string_t *this)
{
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}