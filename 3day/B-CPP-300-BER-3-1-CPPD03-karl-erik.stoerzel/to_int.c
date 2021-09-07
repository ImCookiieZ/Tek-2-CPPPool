/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** to_int.c
*/

#include "string.h"

int to_int (const string_t *this)
{
    return (atoi(this->str));
}