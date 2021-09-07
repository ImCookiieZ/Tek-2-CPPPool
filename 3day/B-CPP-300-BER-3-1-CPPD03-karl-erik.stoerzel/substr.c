/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** substr.c
*/

#include "string.h"

void set_arguments(int len, int *offset, int *length)
{
    if ((*offset) < 0) {
        (*offset) = len + (*offset);
    }
    if ((*length) < 0) {
        (*offset) += (*length);
        (*length) *= -1;
    }
    if ((*offset) < 0) {
        (*length) += (*offset);
        (*offset) = 0;
    }
}

string_t *substr(const  string_t *this, int offset, int length)
{
    string_t *ret = malloc(sizeof(string_t));
    int len = (int) strlen(this->str);

    set_arguments(len, &offset, &length);
    char *new_str;
    size_t size = strlen(this->str) - offset;
    size = size < length ? size : length;
    new_str = malloc(sizeof(char) * (size + 1));
    new_str[size] = 0;

    for (int i = offset; i < size + offset && this->str[i]; i++) {
        new_str[i - offset] = this->str[i];
    }
    string_init(ret, new_str);
    return (ret);
}