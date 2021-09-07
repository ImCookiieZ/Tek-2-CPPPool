/*
** EPITECH PROJECT, 2021
** PSU_navy_2019
** File description:
** bitmap.h
*/

#ifndef PSU_NAVY_2019_BITMAP_H

#define PSU_NAVY_2019_BITMAP_H

#endif //PSU_NAVY_2019_BITMAP_H

#include <stdint.h>
#include <fcntl.h>
#include <glob.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "drawing.h"

#define ERROR 84
#define OK 0

#if BYTE_ORDER == ORDER_LITTLE_ENDIAN
    #define MAGIC (0x424D);
#else
    #define MAGIC (0x4D42);
#endif

typedef struct __attribute__((packed)) structure_bmp_header {
    uint16_t magic;
    uint32_t size;
    uint16_t _app1;
    uint16_t _app2;
    uint32_t offset;
} bmp_header_t;

typedef struct __attribute__((packed)) structure_bmp_info_header {
    uint32_t size;
    int32_t  width;
    int32_t  height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} bmp_info_header_t;

void make_bmp_header(bmp_header_t *header, size_t size);
void make_bmp_info_header(bmp_info_header_t *header, size_t size);
