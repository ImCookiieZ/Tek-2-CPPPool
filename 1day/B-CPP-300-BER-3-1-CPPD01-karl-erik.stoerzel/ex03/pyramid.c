/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** pyramid.c
*/

#include <stdlib.h>

int pyramid_path(int size, const int **map)
{
    int *memo = malloc(sizeof(int) * size);
    int n = size - 1;

    if (memo == NULL)
        return (-1);
    for (int i = 0; i < size; i++)
        memo[i] = map[n][i];
    for (int i = size - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            memo[j] = map[i][j] + (memo[j] < memo[j + 1] ?
memo[j] : memo[j + 1]);
        }
    }
    return memo[0];
}