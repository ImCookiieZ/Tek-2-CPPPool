/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** genetic_basic.c
*/

#include <lzma.h>
#include "generic_list.h"

unsigned int list_get_size(list_t list)
{
    if (list == NULL)
        return (0);
    return (list_get_size(list->next) + 1);
}

bool list_is_empty(list_t list)
{
    if (!list)
        return (true);
    return (false);
}

void list_clear(list_t *front)
{
    while (!list_is_empty(*front))
    {
        list_del_elem_at_front(front);
    }
}

void list_dump(list_t list, value_displayer_t value_dis)
{
    while (list) {
        (value_dis)(list->value);
        list = list->next;
    }
}