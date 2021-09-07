/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Mixer.cpp
*/

#include "Mixer.hpp"

int myMixer(FruitBox &fruits)
{
    FruitNode *tmp = fruits.head();
    int ret = 0;

    while (tmp)
    {
        if (tmp->_fruit)
            ret += tmp->_fruit->getVitamins();
    }
    return ret;
}

void Mixer::setPlugg(bool plug)
{
    _plugged = plug;
    if (_plugged)
    {
        _mixfunc = &myMixer;
    }
}

Mixer::Mixer()
{
    _mixfunc = nullptr;
    _plugged = false;
}
