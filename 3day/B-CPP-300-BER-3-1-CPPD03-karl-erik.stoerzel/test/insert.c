/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** insert.c
*/

#include "string.h"
#include <stdio.h>

void insert_c(string_t *this, size_t pos, const char *str)
{
    size_t len = strlen(this->str);
    size_t len2 = strlen(str);
    size_t index = pos < len ? pos : len;
    char *new = malloc(sizeof(char) * (len + len2 + 1));
    memset(new, 0, len + len2);
    strncpy(new, this->str, index);
    strcat(new, str);
    strcat(new, &this->str[index]);
    free(this->str);
    this->str = new;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    size_t len = strlen(this->str);
    size_t len2 = strlen(str->str);
    size_t index = pos < len ? pos : len;
    char *new = malloc(sizeof(char) * (len + len2 + 1));
    memset(new, 0, len + len2);
    strncpy(new, this->str, index);
    strcat(new, str->str);
    strcat(new, &this->str[index]);
    free(this->str);
    this->str = new;
}