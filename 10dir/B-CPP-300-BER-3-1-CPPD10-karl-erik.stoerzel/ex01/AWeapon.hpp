/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AWeapon.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AWEAPON_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
protected:
    std::string _name;
    int _damage;
    int _apCost;
public:
    AWeapon(const std::string &name, int apcost, int damage);

    virtual ~AWeapon();
    std::string getName() const;
    int getAPCost() const;
    int getDamage() const;

    virtual void attack() const = 0;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AWEAPON_HPP
