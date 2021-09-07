/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** vertex.c
*/

#include "new.h"
#include "vertex.h"
#include <stdio.h>

typedef struct
{
    Class   base;
    int     x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL)
        raise("pointer is null");
    if (args == NULL)
        raise("not enough arguments given");
    this->x = va_arg(*args, int );
    this->y = va_arg(*args, int );
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

int get_digits_vertex(int i)
{
    int digit = 0;

    if (i < 0) {
        i *= -1;
        digit++;
    }
    while (i > 9) {
        digit++;
        i /= 10;
    }
    return (digit + 1);
}

static char *Vertex_str(VertexClass *this)
{
    size_t size = get_digits_vertex(this->x) + get_digits_vertex(this->y) + \
    get_digits_vertex(this->z) + (int)strlen(this->base.__name__) + 9;
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size + 1, "<%s (%d, %d, %d)>", this->base.__name__, this->x,
        this->y, this->z);
    return (str);
}

Object *Vertex_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((VertexClass *)this)->x + ((VertexClass *)other)->x;
    int y = ((VertexClass *)this)->y + ((VertexClass *)other)->y;
    int z = ((VertexClass *)this)->z + ((VertexClass *)other)->z;
    VertexClass *obj = new(Vertex, x, y, z);
    return (obj);
}

Object *Vertex_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((VertexClass *)this)->x - ((VertexClass *)other)->x;
    int y = ((VertexClass *)this)->y - ((VertexClass *)other)->y;
    int z = ((VertexClass *)this)->z - ((VertexClass *)other)->z;
    VertexClass *obj = new(Vertex, x, y, z);
    return (obj);
}
// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;