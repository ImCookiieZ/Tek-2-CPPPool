/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** add.c
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a = a * -1;
    if (b < 0)
        b = b * -1;
    return (a + b);
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL) {
        operation->add_op.res = normal_add(operation->add_op.a,
            operation->add_op.b);
    }
    if (operation->add_type == ABSOLUTE) {
        operation->add_op.res = absolute_add(operation->add_op.a,
            operation->add_op.b);
    }
}
