/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** del_element.c
*/

#include "double_list.h"
#include <stdlib.h>
#include <lzma.h>

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t start = *front_ptr;
    if (*front_ptr == NULL)
        return (false);
    *front_ptr = start->next;
    free(start);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t start = *front_ptr;
    double_list_t end = NULL;
    if (front_ptr == NULL)
        return (false);
    while (start->next != NULL)
    {
        end = start;
        start = start->next;
    }
    if (end != NULL)
        end->next = NULL;
    else {
        *front_ptr = NULL;
    }
    free(start);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr, unsigned int
position)
{
    double_list_t start = *front_ptr;
    double_list_t end = NULL;
    unsigned int i = 0;
    if (front_ptr == NULL)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    while (start->next != NULL) {
        if (i == position) {
            end->next = start->next;
            free(start);
            return (true);
        }
        end = start;
        start = start->next;
        i++;
    }
    if (i == position)
        return (double_list_del_elem_at_back(front_ptr));
    return (false);
}