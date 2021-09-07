/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Paladin.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PALADINS_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PALADINS_HPP

#include "Warrior.hpp"
#include "Priest.hpp"
#include "Character.hpp"

class Paladin : virtual public Warrior, virtual public Priest
{
public:
    Paladin(std::string name, int level, std::string weapon = "hammer");
    int CloseAttack() override ;
    int RangeAttack() override ;
    void Heal() override;
    void RestorePower() override;
    int Intercept();
};

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PALADINS_HPP
