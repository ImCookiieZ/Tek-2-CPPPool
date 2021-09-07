/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** split_c.c
*/

#include "string.h"

string_t **create_split_string(char **string, int len)
{
    string_t **ret = malloc(sizeof(string_t *) * len);

    ret[len - 1] = NULL;
    for (int i = 0; i < len - 1; i++) {
        ret[i] = malloc(sizeof(string_t));
        string_init(ret[i], string[i]);
        ret[i]->malloced = 1;
        free(string[i]);
    }
    free(string);
    return (ret);
}

args_t get_args_s(const string_t *this, char separator, args_t *args,
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

string_t **split_s(const string_t *this, char separator)
{
    if (this == NULL)
        return (NULL);
    args_t args = {
        this->str, 0, 0, strlen(this->str),
        count_separator(this->str, separator) + 2
    };
    char **ret = malloc(sizeof(char *) * args.y);
    ret[args.y - 1] = NULL;
    args = get_args_s(this, separator, &args, ret);
    ret[args.j] = malloc(sizeof(char) * (args.len_word + 1));
    ret[args.j] = strncpy(ret[args.j], args.tmp, args.len_word);
    ret[args.j][args.len_word] = '\0';
    return (create_split_string(ret, args.y));
}