/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** ex00.h
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_EX00_H
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_EX00_H

typedef struct cthulhu_s
{
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s
{
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

//cthulhu
cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);

//koala
koala_t *new_koala(char *name, char is_a_legend);
void eat(koala_t *this);

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_EX00_H
