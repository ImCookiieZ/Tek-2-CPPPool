/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** tree_destroy.c
*/

#include "tree_traversal.h"
#include <stdlib.h>

bool tree_destroy(tree_t *tree_ptr)
{
    if (*tree_ptr == NULL)
        return (false);
    while ((*tree_ptr)->children) {
        tree_node_t *new = list_get_elem_at_front((*tree_ptr)->children);
        tree_destroy(&new);
        list_del_elem_at_front(&(*tree_ptr)->children);
    }
    free(*tree_ptr);
    *tree_ptr = NULL;
    return (true);
}