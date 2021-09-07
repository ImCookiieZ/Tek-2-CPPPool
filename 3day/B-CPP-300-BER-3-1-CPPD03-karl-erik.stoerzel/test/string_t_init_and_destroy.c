/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** string_t_init_and_destroy.c
*/

#include "string.h"

void string_destroy(string_t *this)
{
    free(this->str);
    this->string_init = NULL;
    this->string_destroy = NULL;
//    if (this->malloced == 1)
//        free(this);
}

void init_more(string_t *this)
{
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->malloced = 0;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->string_destroy = &string_destroy;
    this->string_init = &string_init;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->print = &print;
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->join_c = &join_c;
    this->join_s = &join_s;
    this->substr = &substr;
    init_more(this);
}