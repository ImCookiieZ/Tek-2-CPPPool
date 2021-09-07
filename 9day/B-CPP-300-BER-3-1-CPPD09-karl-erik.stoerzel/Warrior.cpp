/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"

Warrior::Warrior(std::string name, size_t level, std::string weaponName) : Character(name, level)
{
    this->_weaponName = weaponName;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" <<
    std::endl;
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
}

int Warrior::RangeAttack()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        if (this->Range == Character::CLOSE)
            return 0;
        std::cout << this->_name << " intercepts"<< std::endl;
        this->Range = Character::CLOSE;
    }
    else
        notEnoughEnergy();
    return 0;
}

int Warrior::CloseAttack()
{
    if (this->_power >= 30)
    {
        this->_power -= 30;
        if (this->Range == Character::RANGE)
            return 0;
        std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
        return (20 + this->_strength);
    }
    else
        notEnoughEnergy();
    return 0;
}
