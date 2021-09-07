/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Mixer.hpp
*/

#ifndef MORNING_MIXER_HPP
#define MORNING_MIXER_HPP

#include "MixerBase.hpp"

class Mixer : public MixerBase
{
public:
    Mixer();
    void setPlugg(bool plug);
};
int myMixer(FruitBox &fruits);

#endif //MORNING_MIXER_HPP
