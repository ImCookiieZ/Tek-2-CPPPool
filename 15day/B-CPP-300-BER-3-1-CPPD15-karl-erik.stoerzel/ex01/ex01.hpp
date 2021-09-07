/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex01.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX01_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX01_HPP

#include <cstring>

template<typename T>
int compare(const T &a, const T &b)
{
    return (a == b ? 0 : (a < b ? -1 : 1));
}

int compare(const char * const &a, const char * const &b)
{
    int cmp = strcmp(a, b);
    return compare(cmp, 0);
}

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX01_HPP
