/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** int.c
*/

#include "string.h"
#include "new.h"
#include "all_classes.h"
#include "array.h"

static void string_ctor(StringClass *this, va_list *args)
{
    if (this == NULL)
        raise("string is null");
    if (args == NULL)
        raise("not enough arguments given");
    char *str = va_arg(*args, char *);
    if (str == NULL)
        raise("string is null");
    this->str = strdup(str);
}

static void string_dtor(StringClass *this)
{
    free(this->str);
}

static char *string_str(StringClass *this)
{
    size_t size = strlen(this->str) + 5 + strlen(this->base.__name__);
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        raise("Malloc failed");
    memset(str, 0, size);
    snprintf(str, size + 1, "<%s (%s)>", this->base.__name__, this->str);
    return (str);
}

char *add_string(char *src, char *add)
{
    size_t len = strlen(src) + strlen(add);
    char *dest = malloc(sizeof(char) * (len + 1));
    strcpy(dest, src);
    strcat(dest, add);
    return (dest);
}

StringClass *string_add(const Object *this, const Object *other)
{
    char *tmp = malloc(1000);
    char *str = NULL;
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (strcmp(((Class *)other)->__name__, "Int") == 0) {
        sprintf(tmp, "%d", ((IntClass *) other)->x);
        str = add_string(((StringClass *)this)->str, tmp);
        free(tmp);
    }
    if (strcmp(((Class *)other)->__name__, "Float") == 0) {
        sprintf(tmp, "%f", ((FloatClass *) other)->x);
        str = add_string(((StringClass *)this)->str, tmp);
        free(tmp);
    }
    if (strcmp(((Class *)other)->__name__, "Char") == 0) {
        sprintf(tmp, "%c", ((CharClass *) other)->c);
        str = add_string(((StringClass *)this)->str, tmp);
        free(tmp);
    }
    else if (strcmp(((Class *)other)->__name__, "String") == 0)
        str = add_string(((StringClass *)this)->str,
        ((StringClass *)other)->str);
    StringClass *obj = new(String, str);
    free(str);
    return (obj);
}

StringClass *string_sub(const Object *this, const Object *other)
{
//    if (this == NULL || other == NULL)
//        raise("Null pointer is given");
//    int c = ((StringClass *)this)->str - ((StringClass *)other)->str;
//    StringClass *obj = new(String, c);
    return (NULL);
}

char *mul_string(char *src, float times)
{
    size_t string_len = strlen(src);
    size_t len = (float)string_len * times;
    char *dest = malloc(sizeof(char) * (len + 1));
    memset(dest, 0, len);
    strncpy(dest, src, len < string_len ? len : string_len);

    int i = 0;
    while (i < (int)times - 1)
    {
        strcat(dest, src);
        i++;
    }
    int rest = string_len * (times - (int)times);
    if (rest > 0)
        strncat(dest, src, rest);
    return (dest);
}

StringClass *string_mul(const Object *this, const Object *other)
{
    StringClass *obj = NULL;
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    char *str;
    if (strcmp(((Class *)other)->__name__, "Int") == 0)
    {
        str = mul_string(((StringClass *)this)->str, (float)((IntClass *)
        other)->x);
        obj = new(String, str);
    }
    else if (strcmp(((Class *)other)->__name__, "Float") == 0)
    {
        str = mul_string(((StringClass *)this)->str, ((FloatClass *)
            other)->x);
        obj = new(String, str);
    }
    return (obj);
}

bool string_eq(const StringClass *this, const StringClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    if (strcmp(this->str, this->str) == 0)
        return (true);
    return (false);
}

bool string_lt(const StringClass *this, const StringClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    int i = strcmp(this->str, other->str);
    if (i < 0)
        return (true);
    return (false);
}

bool string_gt(const StringClass *this, const StringClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer is given");
    char *str1 = this->str;
    char *str2 = other->str;
    strlen(str1);
    strlen(str2);
    int i = strcmp(str1, str2);
    if (i > 0)
        return (true);
    return (false);
}

static const StringClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(StringClass),
        .__name__ = "String",
        .__ctor__ = (ctor_t)&string_ctor,
        .__dtor__ = (dtor_t)&string_dtor,
        .__str__ = (to_string_t)&string_str,
        .__add__ = (binary_operator_t)&string_add,
        .__sub__ = (binary_operator_t)&string_sub,
        .__mul__ = (binary_operator_t)&string_mul,
        .__div__ = NULL,
        .__eq__ = (binary_comparator_t)&string_eq,
        .__gt__ = (binary_comparator_t)&string_gt,
        .__lt__ = (binary_comparator_t)&string_lt
    },
    .str = NULL
};

const Class   *String = (const Class *)&_description;