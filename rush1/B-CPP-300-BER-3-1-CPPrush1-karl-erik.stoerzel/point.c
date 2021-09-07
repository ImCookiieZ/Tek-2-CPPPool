/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        raise("pointer is null");
    if (args == NULL)
        raise("not enough arguments given");
    this->x = va_arg(*args, int );
    this->y = va_arg(*args, int );
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

int get_digits_point(int i)
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

static char *Point_str(PointClass *this)
{
    size_t size = get_digits_point(this->x) + get_digits_point(this->y) + \
    (int)strlen(this->base.__name__) + 7;
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size + 1, "<%s (%d, %d)>", this->base.__name__, this->x,
        this->y);
    return (str);
}

PointClass *Point_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((PointClass *)this)->x + ((PointClass *)other)->x;
    int y = ((PointClass *)this)->y + ((PointClass *)other)->y;
    PointClass *obj = new(Point, x, y);
    return (obj);
}

PointClass *Point_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((PointClass *)this)->x - ((PointClass *)other)->x;
    int y = ((PointClass *)this)->y - ((PointClass *)other)->y;
    PointClass *obj = new(Point, x, y);
    return (obj);
}
// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
