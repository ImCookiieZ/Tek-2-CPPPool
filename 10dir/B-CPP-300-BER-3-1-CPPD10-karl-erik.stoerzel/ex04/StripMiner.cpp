/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** StripMiner.cpp
*/

#include "StripMiner.hpp"

void StripMiner::mine(IAsteroid *astro)
{
    std::cout << "* mining deep ... got " << astro->beMined(this) << "! *" << std::endl;
}

StripMiner::~StripMiner()= default;
