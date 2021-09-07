/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** genetic_get_element.c
*/

#include <lzma.h>
#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int
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

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t value_comp)
{
    while (list)
    {
        if ((value_comp)(list->value, value) == 0)
            return (list);
        list = list->next;
    }
    return (NULL);
}