/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Hunter.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_HUNTER_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_HUNTER_HPP

#include "Warrior.hpp"

class Hunter : public Warrior
{
public:
    Hunter(std::string name, int level, std::string weapon = "sword");
    int CloseAttack() override;
    int RangeAttack() override;
    void RestorePower() override;
};

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_HUNTER_HPP
