/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** find.c
*/

#include "string.h"

int find_s(const  string_t *this, const string_t *str, size_t pos)
{
    char *first = strstr(&this->str[pos], str->str);
    if (first == NULL)
        return (-1);
    return ((int) (first - this->str));
}

int find_c(const string_t *this, const  char *str, size_t pos)
{
    char *first = strstr(&this->str[pos], str);
    if (first == NULL)
        return (-1);
    return ((int) (first - this->str));
}