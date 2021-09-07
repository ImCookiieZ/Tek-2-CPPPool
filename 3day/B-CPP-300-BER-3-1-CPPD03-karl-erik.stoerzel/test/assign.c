/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** assign.c
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}