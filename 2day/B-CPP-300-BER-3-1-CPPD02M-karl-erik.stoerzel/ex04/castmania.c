/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** castmania.c
*/

#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *data2 = (instruction_t *)data;
    if (instruction_type == ADD_OPERATION)
    {
        exec_add(data2->operation);
        if (data2->output_type == VERBOSE)
            printf("%i\n", ((addition_t *) data2->operation)->add_op.res);
    }
    if (instruction_type == DIV_OPERATION) {
        exec_div(data2->operation);
        if (data2->output_type == VERBOSE) {
            if (((division_t *) data2->operation)->div_type == INTEGER) {
                printf("%i\n", ((integer_op_t *) ((division_t *)
                data2->operation)->div_op)->res);
            }
            else {
                printf("%f\n", ((decimale_op_t *)
                ((division_t *) data2->operation)->div_op)->res);
            }
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT)
        printf("%i\n", (int) *((int *)data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", (float) *((float *)data));
    else
        exec_operation(instruction_type, data);
}
