/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** list.c
*/

#include "list.h"


typedef struct {
    Iterator    base;
    ListClass  *_list;
    size_t      _idx;
}   ListIteratorClass;

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, size_t);
}

static bool     ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_idx >= this->_list->size)
        raise("Out of range");
    list_node_t *tmp = this->_list->head;
    for (int i = 0; i < this->_idx; i++)
        tmp = tmp->next;
    return (tmp->element);
}

static void     ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list list;
    if (this->_idx >= this->_list->size)
        raise("index is bigger than the array");
    list_node_t *tmp = this->_list->head;
    for (int i = 0; i < this->_idx; i++)
        tmp = tmp->next;
    delete(tmp->element);
    va_start(list, this);
    tmp->element = va_new(this->_list->type, &list);
    va_end(list);
}

static const ListIteratorClass   ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0
};

static const Class    *ListIterator = (const Class *)&ListIteratorDescr;

static void List_addFront(ListClass *this, ...)
{
    va_list list;
    list_node_t *new_node = malloc(sizeof(list_node_t));
    if (new_node == NULL)
        raise("Malloc failed");
    va_start(list, this);
    new_node->element = va_new(this->type, &list);
    va_end(list);
    new_node->next = this->head;
    new_node->prev = NULL;
    if (this->tail == NULL) {
        this->tail = new_node;
    }
    else {
        this->head->prev = new_node;
    }
    this->head = new_node;
    this->size++;
}

static void List_addBack(ListClass *this, ...)
{
    va_list list;
    list_node_t *new_node = malloc(sizeof(list_node_t));

    va_start(list, this);
    if (new_node == NULL)
        raise("Malloc failed");
    new_node->element = va_new(this->type, &list);
    va_end(list);
    new_node->next = NULL;
    new_node->prev = this->tail;
    if (this->head == NULL) {
        this->head = new_node;
    }
    else {
        this->tail->next = new_node;
    }
    this->tail = new_node;
    this->size++;
}

void List_addAtPosition(ListClass *this, size_t pos, ...)
{
    va_list list;
    list_node_t *new_node = malloc(sizeof(list_node_t));
    list_node_t *tmp = this->head;

    if (new_node == NULL)
        raise("Malloc failed");
    va_start(list, pos);
    new_node->element = va_new(this->type, &list);
    va_end(list);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (this->size < pos)
        raise("index out of range");

    if (pos == 0) {
        new_node->next = this->head;
        new_node->prev = NULL;
        if (this->tail == NULL) {
            this->tail = new_node;
        }
        else {
            this->head->prev = new_node;
        }
        this->head = new_node;
    }
    else if (pos == this->size) {
        new_node->next = NULL;
        new_node->prev = this->tail;
        if (this->head == NULL) {
            this->head = new_node;
        }
        else {
            this->tail->next = new_node;
        }
        this->tail = new_node;
    }
    else {
        for (int i = 0; i != pos - 1; i++)
            tmp = tmp->next;
        new_node->next = tmp->next;
        new_node->prev = tmp;
        tmp->next->prev = new_node;
        tmp->next = new_node;
    }
    this->size++;
}

static void List_ctor(ListClass *this, va_list *args)
{
    va_list reset;

    list_node_t *tmp = NULL;
    list_node_t *tmp_prev = NULL;

    size_t future_size = va_arg(*args, size_t);
    this->size = 0;
    this->type = va_arg(*args, Class *);
    for (size_t i = 0; i < future_size; i++)
    {
        tmp = malloc(sizeof(list_node_t));
        va_copy(reset, *args);
        tmp->element = va_new(this->type, &reset);
        tmp->prev = tmp_prev;
        tmp->next = NULL;
        tmp->index = i;
        if (this->head == NULL)
            this->head = tmp;
        else
            tmp_prev->next = tmp;
        this->size++;
        this->tail = tmp;
        tmp_prev = tmp;
    }
}
static void List_dtor(ListClass *this, va_list *args)
{
    list_node_t *tmp = this->head;
    while (tmp) {
        delete(tmp->element);
        if (tmp->prev)
            free(tmp->prev);
        if (tmp->next)
            tmp = tmp->next;
        else {
            free(tmp);
            break;
        }
    }
}

static size_t List_len(ListClass *this)
{
    return (this->size);
}

static Iterator *List_begin(ListClass *list)
{
    if (!list)
        return (NULL);
    return (new (ListIterator, list, 0));
}

static Iterator *List_end(ListClass *list)
{
    if (!list)
        return (NULL);
    return (new(ListIterator, list, list->size));
}

static Object *List_getItem(ListClass *this, ...)
{
    list_node_t *tmp = this->head;
    va_list list;
    size_t i = 0;

    va_start(list, this);
    i = va_arg(list, size_t);
    va_end(list);
    if (i >= this->size)
        return NULL;
    for (int j = 0; j < i; j++)
        tmp = tmp->next;
    return tmp->element;
}

static void List_setItem(ListClass *this, ...)
{
    va_list list;
    size_t i = 0;

    va_start(list, this);
    i = va_arg(list, size_t);
    if (i >= this->size)
        raise("index out of bound");
    list_node_t *tmp = this->head;
    for (int j = 0; j < i; j++)
        tmp = tmp->next;
    delete(tmp->element);
    tmp->element = va_new(this->type, &list);
    va_end(list);
}

static void List_deleteItemAtBack(ListClass *this)
{
    list_node_t *tmp = this->tail;
    if (!this->tail)
        raise("List is empty");
    if (!this->tail->prev)
    {
        this->tail = NULL;
        this->head = NULL;
    }
    else {
        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }
    delete(tmp->element);
    free(tmp);
    this->size--;
}

static void List_deleteItemAtFront(ListClass *this)
{
    list_node_t *tmp = this->head;
    if (!this->head)
        raise("List is empty");
    if (!this->head->next)
    {
        this->tail = NULL;
        this->head = NULL;
    }
    else {
        this->head = this->head->next;
        this->head->prev = NULL;
    }
    delete(tmp->element);
    free(tmp);
    this->size--;
}

static void List_deleteItemAtPosition(ListClass *this, size_t pos)
{
    list_node_t *tmp = this->head;
    if (this->size <= pos)
        raise("index out of range");
    for (size_t i = 0; i < pos; i++)
        tmp = tmp->next;
    if (pos == 0)
        List_deleteItemAtFront(this);
    else if (pos == this->size)
        List_deleteItemAtBack(this);
    else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete(tmp->element);
        free(tmp);
        this->size--;
    }
}

static const ListClass   _descr = {
    { /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getItem,
        .__setitem__ = (setitem_t)&List_setItem,
        .__delitemback__ = (delitem_t)&List_deleteItemAtBack,
        .__delitemfront__ = (delitem_t)&List_deleteItemAtFront,
        .__delitempos__ = (delitem_p_t)&List_deleteItemAtPosition,
        .__additemb__ = (additem_t)&(List_addBack),
        .__additemf__ = (additem_t)&(List_addFront),
        .__additemp__ = (additem_p_t)&List_addAtPosition
    },
    .type = NULL,
    .head = NULL,
    .tail = NULL,
    .size = 0
};

const Class   *List = (const Class *)&_descr;