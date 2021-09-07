/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Priest.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PRIEST_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PRIEST_HPP

#include "Mage.hpp"

class Priest : virtual public Mage
{
public:
    Priest(std::string name, size_t level);

    int CloseAttack() override;
    int RangeAttack() override;
    void Heal() override;
    void RestorePower() override;
};

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_PRIEST_HPP
