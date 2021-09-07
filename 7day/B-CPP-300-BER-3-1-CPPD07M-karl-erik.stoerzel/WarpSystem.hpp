/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** WarpSystem.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_WarpSYSTEM_HPP
#define B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_WarpSYSTEM_HPP

#include <iostream>
#include <string>

namespace WarpSystem
{
    class QuantumReactor
    {
    private:
        bool _stability = true;
    public:
        bool isStable();
        void setStability(bool newStability);
    };

    class Core
    {
    private:
        QuantumReactor *_coreReactor;
    public:
        explicit Core(QuantumReactor *newReactor);
        QuantumReactor *checkReactor();
    };
}

#endif //B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_WarpSYSTEM_HPP
