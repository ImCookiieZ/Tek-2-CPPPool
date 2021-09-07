/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex06.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX06_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX06_HPP

#include <string>
#include <sstream>

std::string valToStr(int n)
{
    std::stringstream ss;
    ss << "int:" << n;
    return ss.str();
}

std::string valToStr(float n)
{
    std::stringstream ss;
    ss << "float:" << n << "f";
    return ss.str();
}

std::string valToStr(std::string str)
{
    std::stringstream ss;
    ss << "string:\"" << str <<"\"";
    return ss.str();
}

template<typename T>
std::string valToStr(T val)
{
    return "???";
}

template<typename A, typename B = A>
class Tuple
{
public:
    Tuple();
    A a;
    B b;
    std::string toString() const;
};

template<typename A, typename B>
std::string Tuple<A, B>::toString() const
{
    std::stringstream ss;
    ss << "[TUPLE [";
    ss << valToStr(a) << "] [" << valToStr(b) <<"]]";
    return ss.str();
}

template<typename A, typename B>
Tuple<A, B>::Tuple()
= default;

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX06_HPP
