/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex02.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX02_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX02_HPP

#include <iostream>

template<typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    return (a <= b ? a : b);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    return (a <= b ? a : b);
}

template<typename T>
const T &templateMin(const T* ar, const int size)
{
    T & tmp = const_cast<T&>(ar[0]);
    for (int i = 1; i < size; i++)
        tmp = min<T>(tmp, ar[i]);
    return tmp;
}

int nonTemplateMin(const int* ar, const int size)
{
    int tmp = ar[0];
    for (int i = 1; i < size; i++)
        tmp = min(tmp, ar[i]);
    return tmp;
}

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX02_HPP
