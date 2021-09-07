/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** tree.c
*/

#include <lzma.h>
#include <stdlib.h>
#include "tree_traversal.h"
#include "stack.h"
#include "queue.h"
#include "generic_list.h"
#include <stdio.h>

bool tree_is_empty(tree_t tree)
{
    if (tree == NULL)
        return (true);
    return (false);
}

void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    (dump_func)(tree_node);
}

bool init_tree(tree_t *tree_ptr, void *data)
{
    *tree_ptr = malloc(sizeof(tree_node_t));
    if (*tree_ptr == NULL)
        return (false);
    (*tree_ptr)->data = data;
    (*tree_ptr)->children = NULL;
    (*tree_ptr)->parent = NULL;
    return (true);
}

tree_node_t *tree_add_child(tree_node_t *tree_node, void *data)
{
    tree_t child = NULL;

    if (tree_node == NULL)
        return (NULL);
    init_tree(&child, data);
    child->parent = tree_node;
    if (list_add_elem_at_back(&tree_node->children, child))
        return (child);
    return (NULL);
}