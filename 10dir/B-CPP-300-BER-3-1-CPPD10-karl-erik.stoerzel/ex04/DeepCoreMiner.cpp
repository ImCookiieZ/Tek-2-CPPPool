/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** DeepCoreMiner.cpp
*/

#include "DeepCoreMiner.hpp"

void DeepCoreMiner::mine(IAsteroid *astro)
{
    std::cout << "* mining deep ... got " << astro->beMined(this) << "! *" << std::endl;
}

DeepCoreMiner::~DeepCoreMiner() = default;
