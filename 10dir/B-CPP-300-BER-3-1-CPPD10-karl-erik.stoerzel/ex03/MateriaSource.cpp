/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** MateriaSource.cpp
*/

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *m)
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

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_mats[i] && _mats[i]->getType() == type)
           return _mats[i]->clone();
    }
    return nullptr;
}

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _mats[i] = nullptr;
}
