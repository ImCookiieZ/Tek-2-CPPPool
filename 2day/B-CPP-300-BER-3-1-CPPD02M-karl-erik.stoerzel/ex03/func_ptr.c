/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
** File description:
** func_ptr.c
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = (int)strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int len = (int)strlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("%s", "42\n");
}

void (*f_pointer[4])(const char *) =
    {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

void do_action(action_t action, const char *str)
{
    f_pointer[action](str);
}