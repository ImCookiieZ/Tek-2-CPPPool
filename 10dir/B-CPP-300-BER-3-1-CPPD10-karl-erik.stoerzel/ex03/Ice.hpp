/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Ice.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ICE_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    AMateria *clone() const override ;
    void use(ICharacter &target) override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ICE_HPP
