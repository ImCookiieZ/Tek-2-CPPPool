/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** func_ptr.h
*/

#ifndef B_CPP_300_BER_3_1_CPPD02M_KARL_ERIK_STOERZEL_FUNC_PTR_H

#define B_CPP_300_BER_3_1_CPPD02M_KARL_ERIK_STOERZEL_FUNC_PTR_H

#endif //B_CPP_300_BER_3_1_CPPD02M_KARL_ERIK_STOERZEL_FUNC_PTR_H

#include "func_ptr_enum.h"
#include <stdio.h>
#include <string.h>
#include <zconf.h>
#include <ctype.h>

void print_normal(const char *str);
void print_reverse(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);