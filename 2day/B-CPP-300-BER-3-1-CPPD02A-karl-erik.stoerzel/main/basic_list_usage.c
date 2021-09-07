/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** basic_list_usage.c
*/

#include <stdio.h>
#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    if (list == NULL)
        return (0);
    return (double_list_get_size(list->next) + 1);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}