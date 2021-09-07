/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "list.h"
#include "int.h"
#include "new.h"
#include "float.h"

void main1();

int         main(void)
{
//    main1();

    Object *list = new(List, 1, Int, 2);
    Object *list2 = new(List, 1, Int, 1);

    Object *list3 = addition(list, list2);
//    fflush(stdout);
//    add_elembp(list, 1, 4);
//    add_elembp(list, 1, 4);
//    add_elembp(list, 0, 4);
//    add_elembp(list, 0, 4);
//    add_elemf(list, 12);
//    add_elemb(list, 90);

    Object  *it = begin(list3);
    Object  *it_end = end(list3);
    printf("array size: %zu\n", len(list3));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(list);
    delete(list2);
    delete(list3);
    return (0);
}

void main1()
{
    Object  *array = new(List, 10, Array, 10, Int, 0);

    add_elemf(array, 10, Int, 1);
    //    setitem(array, 5, );
    setitem(array, 6, 1, Float, 3.2f);
    Object *obj = getitem(array, 6);
    del_elemp(obj, 6);
    printf("array size: %zu\n", len(obj));
    Object  *it = begin(obj);
    Object  *it_end = end(obj);
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
}

