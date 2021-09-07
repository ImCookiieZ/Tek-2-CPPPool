/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** Float.c
*/

#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        raise("Floater is null");
    if (args == NULL)
        raise("not enough arguments given");
    this->x = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void *)this;
}

static char *Float_str(FloatClass *this)
{
    size_t size = 1000;
    char *str = malloc(sizeof(char) * (size));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size, "<%s (%f)>", this->base.__name__, this->x);
    return (str);
}

FloatClass *Float_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    float x = ((FloatClass *)this)->x + ((FloatClass *)other)->x;
    FloatClass *obj = new(Float, x);
    return (obj);
}

FloatClass *Float_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    float x = ((FloatClass *)this)->x - ((FloatClass *)other)->x;
    FloatClass *obj = new(Float, x);
    return (obj);
}

FloatClass *Float_mul(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    float x = ((FloatClass *)this)->x * ((FloatClass *)other)->x;
    FloatClass *obj = new(Float, x);
    return (obj);
}

FloatClass *Float_div(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((FloatClass *)other)->x == 0)
        raise("division by zero is not possible");
    float x = ((FloatClass *)this)->x / ((FloatClass *)other)->x;
    FloatClass *obj = new(Float, x);
    return (obj);
}

bool Float_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((FloatClass *)this)->x == ((FloatClass *)other)->x)
        return (true);
    return (false);
}

bool Float_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((FloatClass *)this)->x < ((FloatClass *)other)->x)
        return (true);
    return (false);
}

bool Float_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((FloatClass *)this)->x > ((FloatClass *)other)->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
