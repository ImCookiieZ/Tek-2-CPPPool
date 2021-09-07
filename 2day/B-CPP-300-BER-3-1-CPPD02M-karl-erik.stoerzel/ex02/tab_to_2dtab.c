/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** tab_to_2dtab.c
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res);

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = malloc(sizeof(int *) * (length + 1));
    (*res)[length] = NULL;
    for (int i = 0; i < length; i++)
    {
        (*res)[i] = malloc(sizeof(int) * (width));
        for (int j = 0; j < width; j++)
        {
            (*res)[i][j] = tab[i * width + j];
        }
    }
}