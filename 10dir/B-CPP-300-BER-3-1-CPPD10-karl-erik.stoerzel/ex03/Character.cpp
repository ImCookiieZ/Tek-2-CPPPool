/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(std::string const &name)
{
    _name = std::string(name);
    for (int i = 0; i < 4; i++)
    {
        _mats[i] = nullptr;
    }
}

Character::Character(Character const &coyFrom)
{
    _name = coyFrom._name;
    for (int i = 0; i < 4; i++)
    {
        _mats[i] = nullptr;
        if (coyFrom._mats[i])
            _mats[i] = coyFrom._mats[i];
    }
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!_mats[i])
        {
            _mats[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _mats[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && _mats[idx])
        _mats[idx]->use(target);
}
Character::~Character() = default;
