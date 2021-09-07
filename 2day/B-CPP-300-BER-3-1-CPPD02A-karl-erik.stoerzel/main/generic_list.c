/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** generic_list.c
*/

#include <lzma.h>
#include <stdlib.h>
#include "generic_list.h"

bool list_del_node(list_t *front_ptr, node_t *node_ptr)
{
    list_t tmp = *front_ptr;
    list_t tmp_delete;

    if (tmp == NULL)
        return (false);
    if (tmp == node_ptr) {
        front_ptr = &(tmp->next);
        return (true);
    }
    while (tmp->next != node_ptr)
    {
        if (tmp->next == NULL)
            return (false);
        tmp = tmp->next;
    }
    tmp_delete = tmp->next;
    tmp->next = tmp_delete->next;
    free(tmp_delete);
    return (true);
}