/*
** EPITECH PROJECT, 2021
** morning
** File description:
** MixerBase.hpp
*/

#ifndef MORNING_MIXERBASE_HPP
#define MORNING_MIXERBASE_HPP

#include "FruitBox.hpp"

class MixerBase
{
public:
    MixerBase();
    int mix(FruitBox &fruits) const;

protected:
    bool _plugged;
    int (*_mixfunc)(FruitBox &fruits);
};
#endif //MORNING_MIXERBASE_HPP
