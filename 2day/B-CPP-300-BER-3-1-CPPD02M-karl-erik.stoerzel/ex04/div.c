/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (a == 0 || b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    float ret = 0;
    if (a != 0 && b != 0)
        ret = (float)a / (float)b;
    return (ret);
}

void exec_div(division_t *operation)
{
    integer_op_t *intres = (integer_op_t *) operation->div_op;
    decimale_op_t *floatres = (decimale_op_t *) operation->div_op;
    if (operation->div_type == INTEGER) {
        intres->res = integer_div(intres->a, intres->b);
        operation->div_op = intres;
    }
    if (operation->div_type == DECIMALE) {
        floatres->res = decimale_div(floatres->a, floatres->b);
        operation->div_op = floatres;
    }
}
