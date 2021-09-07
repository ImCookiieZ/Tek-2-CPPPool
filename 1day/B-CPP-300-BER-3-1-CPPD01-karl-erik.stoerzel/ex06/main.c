/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** main.c
*/

#include <zconf.h>
#include "bitmap.h"
#include <stdio.h>

loop_arguments get_parameters(loop_arguments *args);

void run_function(loop_arguments *args);

void write_32bits(int fd, uint32_t **pixels, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            write(fd, &pixels[i][j], sizeof(pixels[i][j]));
        }
    }
}

int main(int argc, char **argv)
{
    loop_arguments args;
    args.size = -1;
    args.loops = -1;

    if (argc != 4) {
        write(2, "menger_face file_name size level\n", 33);
        return (-84);
    }
    args.filename = argv[1];
    args.x = 0;
    args.y = 0;
    args.size = atoi(argv[2]);
    args.depth = atoi(argv[3]);
    if (args.size < 3 || args.size % 3 != 0 || args.depth < 0)
        return (ERROR);
    if (error_handling(args.size, args.loops) == ERROR)
        return (ERROR);
    run_function(&args);
    for (int i = 0; i < args.size; i++) {
        for (int j = 0; j < args.size; j++) {
            printf("%08X", args.img[i][j]);
        }
        printf("\n");
    }
    return (0);
}

void run_function(loop_arguments *args)
{
    bmp_header_t header;
    bmp_info_header_t header_info;
    (*args).fd = open((*args).filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    make_bmp_header(&header, (*args).size);
    make_bmp_info_header(&header_info, (*args).size);
    write((*args).fd, &header, 32);
    write((*args).fd, &header_info, sizeof(header_info));
    (*args) = get_parameters(args);
    loop((*args));
    write_32bits((*args).fd, (*args).img, (*args).size);
    close((*args).fd);
}

loop_arguments get_parameters(loop_arguments *args)
{
    (*args).loops = (*args).depth - 1;
    (*args).img = malloc(sizeof(int *) * (*args).size);
    for (int i = 0; i < (*args).size; i++) {
        (*args).img[i] = malloc(sizeof(int) * (*args).size);
        for (int j = 0; j < (*args).size; j++) {
            (*args).img[i][j] = 0x00000000;
        }
    }
    return (*args);
}
