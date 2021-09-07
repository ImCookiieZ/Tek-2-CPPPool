/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** at.c
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) < pos)
        return (-1);
    return (this->str[pos]);
}