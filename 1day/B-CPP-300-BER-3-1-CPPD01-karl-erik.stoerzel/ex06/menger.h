/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** menger.h
*/

#ifndef PSU_NAVY_2019_MENGER_H

#define PSU_NAVY_2019_MENGER_H

#endif //PSU_NAVY_2019_MENGER_H

#define ERROR 84
#define OK 0

typedef struct loop_parameters {
    char *filename;
    int fd;
    int x;
    int y;
    int size;
    int loops;
    int depth;
    uint32_t **img;
} loop_arguments;

int main(int argc, char **argv);
int loop(loop_arguments);
int error_handling(int size, int loops);
