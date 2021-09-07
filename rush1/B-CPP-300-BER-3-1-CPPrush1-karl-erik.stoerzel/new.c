/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** new.c
*/

#include "raise.h"
#include "new.h"

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj;

    if (class == NULL)
        raise("class is NULL");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Malloc returned NULL");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

Object *new(const Class *class, ...)
{
    Object  *obj;
    va_list list;

    va_start(list, class);
    obj = va_new(class, &list);
    va_end(list);
    return (obj);
}

void delete(Object *ptr)
{
    Class *base;

    if (ptr == NULL)
        raise("Object is NULL");
    base = ptr;
    if (base->__dtor__)
        (base->__dtor__)(ptr);
    free(ptr);
}