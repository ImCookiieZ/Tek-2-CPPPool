/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** SuperMutant.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SUPERMUTANT_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SUPERMUTANT_HPP

#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
public:
    SuperMutant();
    ~SuperMutant() override;
    void takeDamage(int damage) override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SUPERMUTANT_HPP
