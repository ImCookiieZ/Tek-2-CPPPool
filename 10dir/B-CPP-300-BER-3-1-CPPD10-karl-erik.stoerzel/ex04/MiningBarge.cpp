/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** MiningBarge.cpp
*/

#include "MiningBarge.hpp"

void MiningBarge::equip(IMiningLaser *laser)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_weapons[i])
        {
            _weapons[i] = laser;
        }
    }
}

void MiningBarge::mine(IAsteroid *asteroid) const
{
    for (int i = 0; i < 4; i++)
    {
        if (_weapons[i])
            _weapons[i]->mine(asteroid);
    }
}

MiningBarge::~MiningBarge() = default;

MiningBarge::MiningBarge()
{
    for (int i = 0; i < 4; i++)
        _weapons[i] = nullptr;
}
