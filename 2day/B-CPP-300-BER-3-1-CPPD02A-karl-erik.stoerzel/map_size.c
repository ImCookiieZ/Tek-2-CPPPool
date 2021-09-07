/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** map_size.c
*/

#include "map.h"
#include "generic_list.h"

unsigned int map_get_size(map_t map)
{
    return (list_get_size(map));
}

bool map_is_empty(map_t map)
{
    return (list_is_empty(map));
}