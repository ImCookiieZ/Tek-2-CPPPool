/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Mage.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_MAGE_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_MAGE_HPP

#include "Character.hpp"

class Mage : virtual public Character
{
public:
    Mage(std::string name, size_t level);

    int CloseAttack() override;
    int RangeAttack() override;
    void RestorePower() override;
};

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_MAGE_HPP
