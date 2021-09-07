/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** map.c
*/

#include <zconf.h>
#include "stdlib.h"
#include "map.h"
#include "generic_list.h"

key_comparator_t key_cmp_container(bool store, key_comparator_t new_key_cmp)
{
    static key_comparator_t my_static = NULL;
    if (store == true)
        my_static = new_key_cmp;
    return (my_static);
}

int pair_comparator(void *first, void *second)
{
    key_comparator_t function = key_cmp_container(false, NULL);
    if (function == NULL)
        return (0);
    return ((function)(((pair_t *)(first))->key, ((pair_t *)(second))->key));
}

bool map_add_elem(map_t *map_ptr, void *key, void *value, key_comparator_t
key_cmp)
{
    map_t tmp = *map_ptr;

    pair_t *pair = malloc(sizeof(pair_t));
    if (pair == NULL)
        return (false);
    pair->value = value;
    pair->key = key;
    key_cmp_container(true, key_cmp);
    if (tmp != NULL) {
        for (; tmp != NULL; tmp = tmp->next) {
            if (pair_comparator(tmp->value, pair) == 0) {
                free(tmp->value);
                tmp->value = pair;
                return (true);
            }
        }
    }
    return (list_add_elem_at_back(map_ptr, pair));
}

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t start = *map_ptr;
    unsigned int i = 0;
    key_cmp_container(true, key_cmp);
    if (start == NULL)
        return (false);
    pair_t pair = {key, key};
    if (pair_comparator(&pair, start->value) == 0)
        return (list_del_elem_at_front(map_ptr));
    while (start->next != NULL) {
        if (pair_comparator(&pair, start->value) == 0) {
            free(start);
            return (true);
        }
        start = start->next;
        i++;
    }
    if (pair_comparator(&pair, start->value) == 0)
        return (list_del_elem_at_back(map_ptr));
    return (false);
}

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    pair_t pair = {key, key};
    while (map)
    {
        if (pair_comparator(&pair, map->value) == 0)
            return (((pair_t *)(map->value))->value);
        map = map->next;
    }
    return (NULL);
}