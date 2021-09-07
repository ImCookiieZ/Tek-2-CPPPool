/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** int.c
*/

#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        raise("Inter is null");
    if (args == NULL)
        raise("not enough arguments given");
    this->x = va_arg(*args, int );
}

static void Int_dtor(IntClass *this)
{
    (void *)this;
}

int get_digits_int(int i)
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

static char *Int_str(IntClass *this)
{
    size_t size = get_digits_int(this->x) + 5 + strlen(this->base.__name__);
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size + 1, "<%s (%d)>", this->base.__name__, this->x);
    return (str);
}

IntClass *Int_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((IntClass *)this)->x + ((IntClass *)other)->x;
    IntClass *obj = new(Int, x);
    return (obj);
}

IntClass *Int_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((IntClass *)this)->x - ((IntClass *)other)->x;
    IntClass *obj = new(Int, x);
    return (obj);
}

IntClass *Int_mul(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int x = ((IntClass *)this)->x * ((IntClass *)other)->x;
    IntClass *obj = new(Int, x);
    return (obj);
}

IntClass *Int_div(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((IntClass *)other)->x == 0)
        raise("division by zero is not possible");
    int x = ((IntClass *)this)->x / ((IntClass *)other)->x;
    IntClass *obj = new(Int, x);
    return (obj);
}

bool Int_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((IntClass *)this)->x == ((IntClass *)other)->x)
        return (true);
    return (false);
}

bool Int_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((IntClass *)this)->x < ((IntClass *)other)->x)
        return (true);
    return (false);
}

bool Int_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((IntClass *)this)->x > ((IntClass *)other)->x)
        return (true);
    return (false);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;