/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** int.c
*/

#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        raise("char is null");
    if (args == NULL)
        raise("not enough arguments given");
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void *)this;
}

static char *Char_str(CharClass *this)
{
    size_t size = 1 + 5 + strlen(this->base.__name__);
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size + 1, "<%s (%c)>", this->base.__name__, this->c);
    return (str);
}

CharClass *Char_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int c = ((CharClass *)this)->c + ((CharClass *)other)->c;
    CharClass *obj = new(Char, c);
    return (obj);
}

CharClass *Char_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int c = ((CharClass *)this)->c - ((CharClass *)other)->c;
    CharClass *obj = new(Char, c);
    return (obj);
}

CharClass *Char_mul(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int c = ((CharClass *)this)->c * ((CharClass *)other)->c;
    CharClass *obj = new(Char, c);
    return (obj);
}

CharClass *Char_div(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int c = ((CharClass *)this)->c / ((CharClass *)other)->c;
    CharClass *obj = new(Char, c);
    return (obj);
}

bool Char_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((CharClass *)this)->c == ((CharClass *)other)->c)
        return (true);
    return (false);
}

bool Char_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((CharClass *)this)->c < ((CharClass *)other)->c)
        return (true);
    return (false);
}

bool Char_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (((CharClass *)this)->c > ((CharClass *)other)->c)
        return (true);
    return (false);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;