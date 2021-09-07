/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** PlasmaRifle.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PLASMARIFLE_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    void attack() const override;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_PLASMARIFLE_HPP
