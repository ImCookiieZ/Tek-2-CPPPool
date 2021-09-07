/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD03_karl_erik_stoerzel
** File description:
** string.h
*/

#ifndef B_CPP_300_BER_3_1_CPPD03_KARL_ERIK_STOERZEL_STRING_H

#define B_CPP_300_BER_3_1_CPPD03_KARL_ERIK_STOERZEL_STRING_H

#endif //B_CPP_300_BER_3_1_CPPD03_KARL_ERIK_STOERZEL_STRING_H

#include <string.h>
#include <stdlib.h>

typedef struct args_split_s
{
    char *tmp;
    int j;
    int len_word;
    size_t len;
    int y;
} args_t;

typedef struct string_struct_s
{
    char *str;
    void (*string_init)(struct string_struct_s *, const char *s);
    void (*string_destroy)(struct string_struct_s *);
    void (*assign_s)(struct string_struct_s *, const struct string_struct_s *);
    void (*assign_c)(struct string_struct_s *, const char *);
    void (*append_s)(struct string_struct_s *, const struct string_struct_s *);
    void (*append_c)(struct string_struct_s *, const char *);
    char (*at)(const struct string_struct_s *, size_t);
    void (*clear)(struct string_struct_s *);
    int (*size)(const struct string_struct_s *);
    int (*compare_s)(const struct string_struct_s *, const struct
        string_struct_s *);
    int (*compare_c)(const struct string_struct_s *, const char *);
    size_t (*copy)(const struct string_struct_s *, char *, size_t , size_t);
    const char *(*c_str)(const struct string_struct_s *);
    int (*empty)(const struct string_struct_s *);
    int (*find_s)(const struct string_struct_s *this, const struct
        string_struct_s *str, size_t pos);
    int (*find_c)(const struct string_struct_s *this, const char *str, size_t
        pos);
    void (*insert_c)(struct string_struct_s *, size_t pos, const char *str);
    void (*insert_s)(struct string_struct_s *, size_t pos, const struct
        string_struct_s *str);
    int (*to_int)(const struct string_struct_s *);
    void (*print)(const struct string_struct_s *this);
    char **(*split_c)(const struct string_struct_s *this, char separator);
    struct string_struct_s **(*split_s)(const struct string_struct_s *this,
        char separator);
    void (*join_c)(struct string_struct_s *, char, const char * const *);
    void (*join_s)(struct string_struct_s *, char, const struct
        string_struct_s * const *);
    struct string_struct_s *(*substr)(const  struct string_struct_s *this, int
        offset, int length);
    int malloced;
} string_t;

//ex00
void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

//ex01
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

//ex02
void append_s(string_t *this, const  string_t *ap);
void append_c(string_t *this, const char *ap);

//ex03
char at(const string_t *this, size_t pos);

//ex04
void clear(string_t *this);

//ex05
int size(const string_t *this);

//ex06
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

//ex07
size_t copy(const string_t *this, char *s, size_t n, size_t pos);

//ex08
const char *c_str(const string_t *this);

//ex09
int empty(const string_t *this);

//ex10
int find_s(const  string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const  char *str, size_t pos);

//ex11
void insert_c(string_t *this, size_t pos, const  char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);

//ex12
int to_int (const string_t *this);

//ex13
char **split_c(const string_t *this, char separator);
string_t **split_s(const string_t *this, char separator);
int count_separator(char *str, char separator);

//ex14
void print(const string_t *this);

//ex15
void join_s(string_t *this, char delim, const string_t * const * tab);
void join_c(string_t *this, char delim, const char * const * tab);

//ex16
string_t *substr(const  string_t *this, int offset, int length);