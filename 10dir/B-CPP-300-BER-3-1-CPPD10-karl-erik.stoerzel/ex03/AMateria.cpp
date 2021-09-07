/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AMateria.cpp
*/

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
{
    xp_ = 0;
    _type = type;
}

const std::string &AMateria::getType() const
{
    return _type;
}

unsigned int AMateria::getXP() const
{
    return xp_;
}

void AMateria::use(ICharacter &target)
{
    xp_ += 10;
}
