/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef CONTAINER_H
# define CONTAINER_H

# include "object.h"
# include "iterator.h"
# include "raise.h"

typedef struct Container_s Container;

typedef Iterator *(*iter_t)(Container *this);
typedef size_t (*len_t)(Container *this);
typedef Object *(*getitem_t)(Container *this, ...);
typedef void (*setitem_t)(Container *this, ...);
typedef void (*delitem_t)(Container *this);
typedef void (*delitem_p_t)(Container *this, size_t pos);
typedef void (*additem_t)(Container *this, ...);
typedef void (*additem_p_t)(Container *this, size_t pos, ...);

struct Container_s {
    Class       base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    iter_t      __pos__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
    delitem_t   __delitemback__;
    delitem_t   __delitemfront__;
    delitem_p_t  __delitempos__;
    additem_t   __additemb__;
    additem_t   __additemf__;
    additem_p_t __additemp__;
};

# define len(c)             ((Container *)c)->__len__(c)
# define begin(c)           ((Container *)c)->__begin__(c)
# define end(c)             ((Container *)c)->__end__(c)
# define getitem(c, ...)    ((Container *)c)->__getitem__(c, __VA_ARGS__)
# define setitem(c, ...)    ((Container *)c)->__setitem__(c, __VA_ARGS__)
#define del_elemf(c)        ((Container *)c)->__delitemfront__ != NULL ? ((Container *)c)->__delitemfront__(c) : NULL
#define del_elemb(c)        ((Container *)c)->__delitemback__ != NULL ? ((Container *)c)->__delitemback__(c) : NULL
#define del_elemp(c, i)     ((Container *)c)->__delitempos__ != NULL ? ((Container *)c)->__delitempos__(c, i) : NULL
#define add_elemf(c, ...)     ((Container *)c)->__additemf__ != NULL ? ((Container *)c)->__additemf__(c, __VA_ARGS__) : NULL
#define add_elemb(c, ...)     ((Container *)c)->__additemb__ != NULL ? ((Container *)c)->__additemb__(c, __VA_ARGS__) : NULL
#define add_elembp(c, i, ...)     ((Container *)c)->__additemp__ != NULL ? ((Container *)c)->__additemp__(c, i, __VA_ARGS__) : NULL
#endif
