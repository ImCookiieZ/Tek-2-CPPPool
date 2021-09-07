/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::~AEnemy() = default;

AEnemy::AEnemy(int hp, const std::string &type)
{
    _hp = hp;
    _type = type;
}

std::string AEnemy::getType() const
{
    return _type;
}

int AEnemy::getHP() const
{
    return _hp;
}

void AEnemy::takeDamage(int damage)
{
    this->_hp -= damage;
}
