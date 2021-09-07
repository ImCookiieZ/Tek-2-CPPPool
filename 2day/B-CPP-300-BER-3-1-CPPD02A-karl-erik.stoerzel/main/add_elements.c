/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** add_elements.c
*/

#include "double_list.h"
#include <stdlib.h>
#include <lzma.h>

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new_el = malloc(sizeof(double_list_t));
    if (new_el == NULL)
        return (false);
    new_el->next = *front_ptr;
    new_el->value = elem;
    *front_ptr = new_el;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *node = malloc(sizeof(doublelist_node_t));
    double_list_t tmp;

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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
    unsigned int position)
{
    doublelist_node_t *node = malloc(sizeof(doublelist_node_t));
    double_list_t tmp;
    unsigned int i = 0;
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
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
        return (double_list_add_elem_at_back(front_ptr, elem));
    return (false);
}