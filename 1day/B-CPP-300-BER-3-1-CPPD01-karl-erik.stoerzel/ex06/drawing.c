/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** drawing.c
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size, uint32_t
color)
{
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            img[origin->y + i][j + origin->x] = color;
        }
    }
}