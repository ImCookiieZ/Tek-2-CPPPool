/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** ptr_tricks.c
*/

#include <stdio.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int counter = 0;
    int add = 1;
    if (ptr1 > ptr2)
        add = -1;
    while (ptr1 != ptr2)
    {
        ptr1 += add;
        counter++;
    }
    return (counter);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t *base_pointer = (whatever_t *) 0;
    int *member = &(base_pointer->member);
    size_t offset = (size_t) member - (size_t)base_pointer;
    return (whatever_t *) ((size_t) member_ptr - (offset));
}

int main ( void )
{
    whatever_t test ;
    whatever_t * ptr = get_struct_ptr (& test . member ) ;
    if ( ptr == & test )
        printf ("It works !\n") ;
    return (0) ;
}