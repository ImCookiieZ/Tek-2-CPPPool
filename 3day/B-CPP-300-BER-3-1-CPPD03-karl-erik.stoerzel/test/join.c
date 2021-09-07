/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** join.c
*/

#include "string.h"

size_t get_len_2d_s(const string_t * const * tab)
{
    size_t ret = 0;
    size_t delim = 0;
    for (int i = 0; tab[i]; i++) {
        ret += strlen(tab[i]->str);
        delim++;
    }
    return (ret + delim);
}

size_t get_len_2d(const char * const * tab)
{
    size_t ret = 0;
    size_t delim = 0;
    for (int i = 0; tab[i]; i++) {
        ret += strlen(tab[i]);
        delim++;
    }
    return (ret + delim);
}

void join_c(string_t *this, char delim, const char * const * tab)
{
    int len = get_len_2d(tab);
    char *new_str = malloc(sizeof(char) * len);
    memset(new_str, 0, len);
    char *delim_str = malloc(sizeof(char) * 2);
    delim_str[0] = delim;
    delim_str[1] = 0;
    for (int i = 0; tab[i]; i++) {
        strcat(new_str, tab[i]);
        if (tab[i + 1])
            strcat(new_str, delim_str);
    }
    this->assign_c(this, new_str);
}

void join_s(string_t *this, char delim, const string_t * const * tab)
{
    int len = get_len_2d_s(tab);
    char *new_str = malloc(sizeof(char) * len);
    memset(new_str, 0, len);
    char *delim_str = malloc(sizeof(char) * 2);
    delim_str[0] = delim;
    delim_str[1] = 0;
    for (int i = 0; tab[i]; i++) {
        strcat(new_str, tab[i]->str);
        if (tab[i + 1])
            strcat(new_str, delim_str);
    }
    this->assign_c(this, new_str);
}