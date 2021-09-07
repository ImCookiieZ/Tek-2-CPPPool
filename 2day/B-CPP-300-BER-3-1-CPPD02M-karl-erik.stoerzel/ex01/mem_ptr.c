/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** mem_ptr.c
*/

#include "mem_ptr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_str(const char *str1, const char *str2, char **res)
{
    unsigned long len1 = strlen(str1);
    unsigned long len2 = strlen(str2);
    *res = malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    add_str(str_op->str1, str_op->str2, &str_op->res);
}