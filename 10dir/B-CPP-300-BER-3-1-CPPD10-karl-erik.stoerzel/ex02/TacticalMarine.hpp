/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** TacticalMarine.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_TACTICALMARINE_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : virtual public ISpaceMarine
{
public:
    TacticalMarine();
    explicit TacticalMarine(TacticalMarine const *copyFrom);
    ~TacticalMarine() override;
    void battleCry() const override;
    void rangedAttack() const override ;
    void meleeAttack() const override ;
    ISpaceMarine *clone() const override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_TACTICALMARINE_HPP
