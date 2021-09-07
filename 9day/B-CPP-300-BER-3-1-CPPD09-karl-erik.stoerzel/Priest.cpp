/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(std::string name, size_t level) : Character(name, level), Mage(name, level)
{
    std::cout << this->_name << " enters in the order" << std::endl;
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
}

int Priest::CloseAttack()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        if (this->Range == Character::RANGE)
            return 0;
        std::cout << this->_name << " uses a spirit explosion" << std::endl;
        this->Range = Character::RANGE;
        return (10 + this->_spirit);
    }
    else
        notEnoughEnergy();
    return 0;
}

int Priest::RangeAttack()
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

void Priest::Heal()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
        this->_pv += 70;
        if (this->_pv > 100)
            this->_pv = 100;
    }
    else
        notEnoughEnergy();
}

void Priest::RestorePower()
{
    this->_power += 50 + this->_intelligence;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}
