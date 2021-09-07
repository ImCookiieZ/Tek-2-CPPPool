/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** drawing.h
*/

#include <stdint.h>
#include <glob.h>

#ifndef PSU_NAVY_2019_DRAWING_H

#define PSU_NAVY_2019_DRAWING_H

#endif //PSU_NAVY_2019_DRAWING_H

typedef struct pointer_struct
{
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size, uint32_t
color);
