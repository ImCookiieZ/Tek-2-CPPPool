/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** copy.c
*/

#include "string.h"
#include <stdio.h>

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len;
    if (this == NULL || s == NULL)
        return (0);
    len = strlen(this->str);
    if (pos > len)
        return (0);
    strncpy(s, &this->str[pos], n);
    len = strlen(s);
    return (n < len + 1 ? n : len + 1);
}