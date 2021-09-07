/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Warrior.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_WARRIOR_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_WARRIOR_HPP

#include "Character.hpp"

class Warrior : virtual public Character
{
private:
    std::string _weaponName;
public:
    Warrior(std::string name, size_t level, std::string weaponName = "hammer");

    int CloseAttack() override;
    int RangeAttack() override;
};
#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_WARRIOR_HPP
