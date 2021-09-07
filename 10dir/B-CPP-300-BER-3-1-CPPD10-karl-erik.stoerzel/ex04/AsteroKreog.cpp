/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AsteroKreog.cpp
*/

#include "AsteroKreog.hpp"

AsteroKroeg::~AsteroKroeg()
{
}

std::string AsteroKroeg::getName() const
{
    return "AsteroKroeg";
}

std::string AsteroKroeg::beMined(IMiningLaser *laser) const
{
    return "";
}

std::string AsteroKroeg::beMined(DeepCoreMiner *laser) const
{
    return "Sullite";
}

std::string AsteroKroeg::beMined(StripMiner *laser) const
{
    return "Kreogium";
}
