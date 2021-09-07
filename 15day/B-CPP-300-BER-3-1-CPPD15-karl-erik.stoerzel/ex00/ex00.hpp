/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex00.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX00_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX00_HPP

template<typename T>
T add(T a, T b)
{
    return a + b;
}

template<typename T>
const T &min(T a, T b)
{
    return (a < b ? a : b);
}

template<typename T>
const T &max(T a, T b)
{
    return (a > b ? a : b);
}

template<typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX00_HPP
