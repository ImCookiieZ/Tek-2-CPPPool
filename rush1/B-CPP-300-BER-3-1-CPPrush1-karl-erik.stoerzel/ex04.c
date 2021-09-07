/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush1_karl_erik_stoerzel
** File description:
** ex04.c
*/

#include "object.h"
#include "char.h"
#include "new.h"
#include "int.h"
#include <stdio.h>
#include "list.h"

void compareAndDivide ( Object *a , Object * b )
{
//    if ( gt (a , b ) )
//        printf (" a > b \n ") ;
//    else if ( lt (a , b ) )
//        printf (" a < b \n ") ;
//    else
//        printf (" a == b \n ") ;
    Object  *array = multiplication(a , b );
//    printf("%S\n", (Class *)array)->__name__);
    Object  *it = begin(array);
    Object  *it_end = end(array);
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

int main()
{
    Object *a = new (Int, 3);
    Object *b = new(Char, 'a');
    compareAndDivide(a, b);
}