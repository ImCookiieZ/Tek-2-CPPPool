/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(std::string name, int level, std::string weapon) : Character(name, level),
                                                                    Warrior(name, level, weapon),
                                                                    Mage(name, level), Priest(name,
                                                                        level)
{
    std::cout << "the light falls on " << this->_name << std::endl;
    this->_stamina = 10;
    this->_strength = 9;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
}

int Paladin::CloseAttack()
{
    return Warrior::CloseAttack();
}

int Paladin::RangeAttack()
{
    return Priest::RangeAttack();
}

void Paladin::Heal()
{
    Priest::Heal();
}

void Paladin::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" <<std::endl;
}

int Paladin::Intercept()
{
    return Warrior::RangeAttack();
}
