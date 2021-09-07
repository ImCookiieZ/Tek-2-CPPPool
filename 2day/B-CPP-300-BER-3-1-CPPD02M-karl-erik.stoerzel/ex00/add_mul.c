/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** add_mul.c
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int sum = *first + *second;
    int mul = *first * *second;
    *first = sum;
    *second = mul;
}