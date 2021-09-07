/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(std::string name, size_t level)
{
    this->_name = name;
    this->_level = level;
    std::cout << this->_name << " Created" << std::endl;
}

const std::string &Character::getName()
{
    return this->_name;
}

int Character::getLvl() const
{
    return this->_level;
}

int Character::getPv() const
{
    return this->_pv;
}

int Character::getPower() const
{
    return this->_power;
}

void Character::notEnoughEnergy()
{
    std::cout << this->_name << " out of power" << std::endl;
}

int Character::CloseAttack()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        if (this->Range == Character::RANGE)
            return (0);
        std::cout << this->_name << " strikes with a wooden stick" << std::endl;
        return this->_strength + 10;
    }
    else
        notEnoughEnergy();
    return 0;
}

int Character::RangeAttack()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        std::cout << this->_name << " tosses a stone" << std::endl;
        return this->_strength + 5;
    }
    else
        notEnoughEnergy();
    return 0;
}

void Character::Heal()
{
    if (this->_pv <= 50)
        this->_pv += 50;
    else
        this->_pv = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" <<std::endl;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;
    if (this->_pv <= 0)
    {
        std::cout << this->_name << " out of combat" << std::endl;
        this->_pv = 0;
    }
    else
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
}
