/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AssaultTerminator.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASSAULTTERMINATOR_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : virtual public ISpaceMarine
{
public:
    AssaultTerminator();
    explicit AssaultTerminator(AssaultTerminator const *copyFrom);
    ~AssaultTerminator() override;
    void battleCry() const override;
    void rangedAttack() const override ;
    void meleeAttack() const override ;
    ISpaceMarine *clone() const override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASSAULTTERMINATOR_HPP
