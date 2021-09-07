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
#include "all_classes.h"
#include "float.h"

void compareAndDivide ( Object *a , Object * b )
{
    if ( gt (a , b ) )
        printf (" a > b \n ") ;
    else if ( lt (a , b ) )
        printf (" a < b \n ") ;
    else
        printf (" a == b \n ") ;
//    Object  *array = multiplication(a , b );
//    printf("%S\n", (Class *)array)->__name__);
//    Object  *it = begin(array);
//    Object  *it_end = end(array);
//    while (lt(it, it_end))
//    {
//        char *str = str(getval(it));
//        printf("%s\n", str);
//        free(str);
//        incr(it);
//    }
//    delete(it);
//    delete(it_end);
//    delete(array);
}

int main()
{
    char *str1 = strdup("011");
    char *str2 = strdup("A");
    strcmp(str1, str2);
    Object *a = new (String, str1);
    Object *b = new(String, str2);
    Object *three = new(Float, 1.5);
    Object *c = multiplication(a, three);
    char *s1 = str(a);
    char *s2 = str(b);
    char *s3 = str(c);
    printf("s1: %s\ns2: %s\n%s\n", s1, s2, s3);
    delete(a);
    delete(b);
    delete(c);
    free(str1);
    free(str2);
    free(s3);
    free(s2);
    free(s1);
    compareAndDivide(a, b);
}