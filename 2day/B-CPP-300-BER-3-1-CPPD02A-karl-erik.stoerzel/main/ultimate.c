/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** ultimate.c
*/

#include <lzma.h>
#include <stdlib.h>
#include "tree_traversal.h"
#include "stack.h"
#include "queue.h"
#include "generic_list.h"

void tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func)
{
    list_t tmp;
    tree_t tmp_tree;

    if (!tree)
        return;
    tmp = tree->children;
    (dump_func)(tree->data);
    while (tmp)
    {
        (*container->push_func)(container->container, tmp->value);
        tmp = tmp->next;
    }
    tmp_tree = (*container->pop_func)(container->container);
    tree_traversal(tmp_tree, container, dump_func);
}