/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** append_s.c
*/

#include "string.h"

void append_s(string_t *this, const  string_t *ap)
{
    char *str = malloc(strlen(this->str) + strlen(ap->str) + 1);
    strcpy((str), this->str);
    strcat(str, ap->str);
    free(this->str);
    this->str = strdup(str);
    free(str);
}

void append_c(string_t *this, const char *ap)
{
    char *str = malloc(strlen(this->str) + strlen(ap) + 1);
    strcpy((str), this->str);
    strcat(str, ap);
    free(this->str);
    this->str = strdup(str);
    free(str);
}