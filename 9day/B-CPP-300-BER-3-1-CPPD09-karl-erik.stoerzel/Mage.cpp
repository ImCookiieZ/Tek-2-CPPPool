/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Mage.cpp
*/

#include "Mage.hpp"

Mage::Mage(std::string name, size_t level) : Character(name, level)
{
    std::cout << this->_name << " teleported" << std::endl;
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
}

int Mage::CloseAttack()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        if (this->Range == Character::RANGE)
            return 0;
        std::cout << this->_name << " blinks" << std::endl;
        this->Range = Character::RANGE;
        return (0);
    }
    else
        notEnoughEnergy();
    return 0;
}

int Mage::RangeAttack()
{
    if (this->_power >= 25)
    {
        this->_power -= 25;
        std::cout << this->_name << " launches a fire ball"<< std::endl;
        return 20 + this->_spirit;
    }
    else
        notEnoughEnergy();
    return 0;
}

void Mage::RestorePower()
{
    this->_power += 50 + _intelligence;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}
