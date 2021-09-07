/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** genetic_add.c
*/

#include "generic_list.h"
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_el = malloc(sizeof(node_t));
    if (new_el == NULL)
        return (false);
    new_el->next = *front_ptr;
    new_el->value = elem;
    *front_ptr = new_el;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t node = malloc(sizeof(node_t));
    list_t tmp;

    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = NULL;
    if (*front_ptr == NULL)
        *front_ptr = node;
    else {
        tmp = *front_ptr;
        for (int i = 0; tmp->next != NULL; i++)
            tmp = tmp->next;
        tmp->next = node;
    }
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int
position)
{
    list_t node = malloc(sizeof(list_t));
    list_t tmp;
    unsigned int i = 0;
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (node == NULL || position < 0)
        return (false);
    node->value = elem;
    node->next = NULL;
    tmp = *front_ptr;
    for (i = 0; tmp->next != NULL; i++, tmp = tmp->next) {
        if (i == position - 1) {
            node->next = tmp->next;
            tmp->next = node;
            return (true);
        }
    }
    if (i == position)
        return (list_add_elem_at_back(front_ptr, elem));
    return (false);
}