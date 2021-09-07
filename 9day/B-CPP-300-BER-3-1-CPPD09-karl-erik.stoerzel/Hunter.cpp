/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Hunter.cpp
*/

#include "Hunter.hpp"

Hunter::Hunter(std::string name, int level, std::string weapon) : Character(name, level), Warrior
(name, level, weapon)
{
    _strength = 9;
    _stamina = 0;
    _intelligence = 5;
    _spirit = 6;
    _agility = 25;
    std::cout << this->_name << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack()
{
    return Warrior::CloseAttack();
}

int Hunter::RangeAttack()
{
    if (this->_power >= 25)
    {
        this->_power -= 25;
        std::cout << this->_name << " uses his bow"<< std::endl;
        return (this->_agility + 20);
    }
    else
        notEnoughEnergy();
    return 0;
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}
