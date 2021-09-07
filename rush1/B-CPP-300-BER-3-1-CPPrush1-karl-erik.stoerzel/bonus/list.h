/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** list.h
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_LIST_H

#define B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_LIST_H

#include "array.h"
#include "int.h"
#include "new.h"
#include "raise.h"
#include "object.h"
#include "container.h"
#include "iterator.h"

typedef struct list_linked_s
{
    Object *element;
    struct list_linked_s *prev;
    struct list_linked_s *next;
    int index;
} list_node_t;

typedef struct linked_list_head_s
{
    Container base;
    Class *type;
    list_node_t *head;
    list_node_t *tail;
    size_t size;
} ListClass;

typedef Object *(*list_get)(Container *this);

extern const Class *List;

#endif //B_CPP_300_BER_3_1_CPPRUSH1_KARL_ERIK_STOERZEL_LIST_H
