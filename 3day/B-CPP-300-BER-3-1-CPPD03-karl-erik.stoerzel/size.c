/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** size.c
*/

#include "string.h"

int size(const string_t *this)
{
    if (this->str == NULL)
        return (-1);
    return ((int) strlen(this->str));
}