/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Peon.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PEON_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PEON_HPP

#include "Victim.hpp"

class Peon : virtual public Victim
{
public:
    Peon(std::string name);
    ~Peon();
    void getPolymorphed() const override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PEON_HPP
