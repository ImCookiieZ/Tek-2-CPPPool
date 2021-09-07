/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** get_element.c
*/

#include <lzma.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list, unsigned int
position)
{
    unsigned int i = position;
    if (list == NULL || position < 0)
        return (0);
    while (list->next && i) {
        list = list->next;
        i--;
    }
    if (i != 0)
        return (0);
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
    double value)
{
    while (list)
    {
        if (list->value == value)
            return (list);
        list = list->next;
    }
    return (NULL);
}