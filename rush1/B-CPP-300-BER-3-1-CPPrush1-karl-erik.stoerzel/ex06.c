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

void show_on_main01(Object *list, Object *it, Object *it_end);

void print_main02(Object *list, Object *it, Object *it_end)
{
    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
}

void print_main03(int i, Object *list, Object **it, Object **it_end)
{
    i = 0;
    (*it) = begin(list);
    (*it_end) = end(list);
    printf("list size: %zu\n", len(list));
    printf("printing with getitem and an index");
    while (lt((*it), (*it_end)))
    {
        char *str = str(getitem(list, i));
        printf("%s\n", str);
        free(str);
        incr((*it));
        i++;
    }
}

void print_main04(Object *list, Object *it, Object *it_end)
{
    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        setval(it, 0);
        incr(it);
    }
    delete(it);
    delete(it_end);
}

void print_main04_1(Object *list, Object *it, Object *it_end)
{
    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        setval(it, 0);
        incr(it);
    }
    delete(it);
    delete(it_end);
}

void print_5(int i, Object *list, Object *it, Object *it_end)
{
    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    fflush(stdout);
    i = 0;
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        setitem(list, i, 1);
        fflush(stdout);
        free(str);
        incr(it);
        i++;
    }
    delete(it);
    delete(it_end);
    printf("set all elements to 1 via setitem\n");
}

void main1();

int         main(void)
{
    main1();
    int i = 0;
    Object *list = new(List, 10, Int, 5.5);
    printf("init float list of size 10 filled with 5.5\n");
    Object *it = NULL;
    Object *it_end = NULL;

    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(list);
    printf("deleted list\n");
    delete(it);
    delete(it_end);
    list = new(List, 0, Int);
    printf("init int list of size 0 - so nothing in it");
    show_on_main01(list, it, it_end);
    printf("add element 3 on pos 0");
    add_elembp(list, 0, 3);
    show_on_main01(list, it, it_end);
    printf("add element 4 on first pos 1");
    add_elembp(list, 1, 4);
    show_on_main01(list, it, it_end);
    printf("add element 2 on pos 0");
    add_elembp(list, 0, 2);
    show_on_main01(list, it, it_end);
    printf("add element 1 on pos 0");
    add_elembp(list, 0, 1);
    show_on_main01(list, it, it_end);
    printf("add element 5 on last pos");
    add_elemb(list, 5);
    show_on_main01(list, it, it_end);
    printf("add element 0 on first pos");
    add_elemf(list, 0);
    show_on_main01(list, it, it_end);
    printf("add element 6 on last pos");
    add_elemb(list, 6);
    show_on_main01(list, it, it_end);
    printf("add element 7 on last pos");
    add_elemb(list, 7);
    show_on_main01(list, it, it_end);

    print_main02(list, it, it_end);

    print_main03(i, list, &it, &it_end);
    delete(it);
    delete(it_end);
    i = 0;
    del_elemf(list);
    printf("delete first element");
    print_main04(list, it, it_end);
    del_elemb(list);
    printf("delete last element");
    print_main04(list, it, it_end);
    //    del_elemf(list);
    del_elemp(list, 4);
    printf("delete element on position 4");

    print_main04_1(list, it, it_end);
    printf("set all elements to 0 via setvalue\n");
    print_main04(list, it, it_end);

    print_5(i, list, it, it_end);

    //    main00(&list);
//    main01(list, it, it_end);

//    main02(i, list, it, it_end);
//    main03(list, it, it_end);
//    main05(i, list, it, it_end);
//    main06(list, it, it_end);

    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    fflush(stdout);
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        fflush(stdout);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(list);
    return (0);
}
void show_on_main01(Object *list, Object *it, Object *it_end)
{
    it = begin(list);
    it_end = end(list);
    printf("list size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        char *str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
}

void main1()
{
    Object  *list = new(List, 10, Array, 10, Int, 0);

    add_elemf(list, 10, Int, 1);
    //    setitem(list, 5, );
    setitem(list, 6, 2, Float, 3.2f);
    Object *obj = getitem(list, 6);
    del_elemp(obj, 6);
    printf("list size: %zu\n", len(obj));
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
    delete(list);
}

