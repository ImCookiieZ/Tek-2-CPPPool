/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** menger.c
*/

#include "drawing.h"

void write_color(loop_arguments args);

void write_color(loop_arguments args)
{
    unsigned int shift = (0xFF) / (args.depth -
                                   args.loops);
    shift = (((shift << 8) + shift) << 8) + shift;
    int empty_size = args.size / 3;
    point_t org = {args.size / 3 + args.x, args.size / 3 + args.y} ;
    draw_square(args.img, &org, empty_size, shift);
}

int loop(loop_arguments args)
{
    loop_arguments tmp_args = args;
    write_color(args);
    if (args.loops == 0) {
        return (0);
    }
    for (int i = 0; i < args.size; i += args.size / 3) {
        for (int j = 0; j < args.size; j += args.size / 3) {
            if (!(i == args.size / 3 && j == args.size / 3)) {
                tmp_args.size = args.size / 3;
                tmp_args.loops = args.loops - 1;
                tmp_args.x = i + args.x;
                tmp_args.y = j + args.y;
                loop(tmp_args);
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