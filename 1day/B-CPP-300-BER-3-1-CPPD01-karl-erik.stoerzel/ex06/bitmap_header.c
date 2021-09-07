/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** bitmap_header.c
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = MAGIC;
    header->size = 4 * size * size + 54;
    header->offset = 54;
    header->_app1 = 0;
    header->_app2 = 0;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->bpp = 32;
    header->size = 40;
    header->height = size;
    header->width = size;
    header->planes = 1;
    header->raw_data_size = 4 * size * size;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
    header->compression = 0;
}