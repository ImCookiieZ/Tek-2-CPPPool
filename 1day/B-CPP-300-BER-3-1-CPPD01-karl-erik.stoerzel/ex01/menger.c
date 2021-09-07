/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** menger.c
*/

#include "menger.h"
#include <stdlib.h>
#include <stdio.h>

int loop(int size, int loops, int x, int y)
{
    int empty_size = size / 3;
    int empty_x = size / 3 + x;
    int empty_y = size / 3 + y;
    printf("%03i %03i %03i\n", empty_size, empty_x, empty_y);

    if (loops <= 0) {
        return (0);
    }
    for (int i = 0; i < size; i += size / 3) {
        for (int j = 0; j < size; j += size / 3) {
            if (!(i == size / 3 && j == size / 3)) {
                loop(size / 3, loops - 1, i + x, j + y);
            }
        }
    }
    return (0);
}

int error_handling(int size, int loops)
{
    int check = 1;
    for (int i = 0; i < loops; i++)
    {
        check *= 3;
        if (check > size)
            return (ERROR);
    }
    return (OK);
}

int main(int argc, char **argv)
{
    int size = -1;
    int loops = -1;

    if (argc != 3)
        return (84);
    size = atoi(argv[1]);
    loops = atoi(argv[2]);
    if (size < 3 || size % 3 != 0 || loops < 0)
        return (ERROR);
    if (error_handling(size, loops) == ERROR)
        return (ERROR);
    loop(size, loops - 1, 0, 0);
    return (0);
}