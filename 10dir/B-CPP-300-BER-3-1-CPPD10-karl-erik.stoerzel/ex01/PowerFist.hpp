/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** PowerFist.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_POWERFIST_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    void attack() const override;
};


#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_POWERFIST_HPP
