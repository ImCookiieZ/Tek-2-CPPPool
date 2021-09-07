/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex03.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX03_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX03_HPP

#include <iostream>

template<typename T>
void foreach(const T *ar, void (func)(const T &type), const int size)
{
    for (int i = 0; i < size; i++)
    {
        func(ar[i]);
    }
}

template<typename T>
void print(const T &a)
{
    std::cout << a << std::endl;
}

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX03_HPP
