/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name)
{
    _ap = 40;
    _name = name;
    _weapon = nullptr;
}

void Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 0;
}

void Character::attack(AEnemy *enemy)
{
    if (_weapon && enemy)
    {
        int cost = _weapon->getAPCost();
        if (cost <= _ap)
        {
            std::cout << _name << " attacks " << enemy->getType() << " with a " <<
            _weapon->getName() << std::endl;
            enemy->takeDamage(_weapon->getDamage());
            _weapon->attack();
            if (enemy->getHP() <= 0)
                delete enemy;
            _ap -= cost;
        }
    }
}

std::string Character::getName() const
{
    return _name;
}

int Character::getAp() const
{
    return _ap;
}

AWeapon *Character::getWeapon() const
{
    return _weapon;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

std::ostream &operator<<(std::ostream &stream, const Character &character)
{
    AWeapon *tmp = character.getWeapon();
    stream << character.getName() << " has " << character.getAp() << " AP and ";
    if (character.getWeapon())
        stream << "wields a " << tmp->getName() << std::endl;
    else
        stream << "is unarmed" << std::endl;
    return stream;
}