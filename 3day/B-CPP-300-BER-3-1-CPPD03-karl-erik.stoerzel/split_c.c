/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** split.c
*/

#include "string.h"
#include <stdio.h>

int count_separator(char *str, char separator)
{
    int counter = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == separator)
            counter++;
    }
    return (counter);
}

args_t get_args_c(const string_t *this, char separator, args_t *args,
    char **ret)
{
    for (int i = 0; i < (*args).len; i++) {
        if (this->str[i] == separator) {
            ret[(*args).j] = malloc(sizeof(char) * ((*args).len_word + 1));
            ret[(*args).j] = strncpy(ret[(*args).j], (*args).tmp,
                (*args).len_word);
            ret[(*args).j][(*args).len_word] = '\0';
            (*args).j++;
            (*args).tmp += (*args).len_word + 1;
            (*args).len_word = 0;
        }
        else
            (*args).len_word++;
    }
    return (*args);
}

char **split_c(const string_t *this, char separator)
{
    if (this == NULL)
        return (NULL);
    args_t args = {
        this->str, 0, 0, strlen(this->str),
        count_separator(this->str, separator) + 2
    };
    char **ret = malloc(sizeof(char *) * args.y);
    ret[args.y - 1] = NULL;
    args = get_args_c(this, separator, &args, ret);
    ret[args.j] = malloc(sizeof(char) * (args.len_word + 1));
    ret[args.j] = strncpy(ret[args.j], args.tmp, args.len_word);
    ret[args.j][args.len_word] = '\0';
    return (ret);
}