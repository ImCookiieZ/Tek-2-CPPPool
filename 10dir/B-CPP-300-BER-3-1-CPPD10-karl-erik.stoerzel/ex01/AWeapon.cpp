/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    _name = name;
    _apCost = apcost;
    _damage = damage;
}

std::string AWeapon::getName() const
{
    return _name;
}

int AWeapon::getAPCost() const
{
    return _apCost;
}

int AWeapon::getDamage() const
{
    return _damage;
}

AWeapon::~AWeapon()
= default;
