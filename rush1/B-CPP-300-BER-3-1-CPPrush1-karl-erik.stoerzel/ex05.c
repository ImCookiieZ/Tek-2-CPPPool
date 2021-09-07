/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "array.h"
#include "int.h"
#include "new.h"

int         main(void)
{
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    setitem(array, 5, 12);
    setitem(array, 6, 13);
    printf("array size: %zu\n", len(array));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    return (0);
}

