/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** KoalaSteroid.cpp
*/

#include "KoalaSteroid.hpp"

KoalaSteroid::~KoalaSteroid()
{
}

std::string KoalaSteroid::getName() const
{
    return "KoalaSteroid";
}

std::string KoalaSteroid::beMined(IMiningLaser *laser) const
{
    return "";
}

std::string KoalaSteroid::beMined(DeepCoreMiner *laser) const
{
    return "Zazium";
}

std::string KoalaSteroid::beMined(StripMiner *laser) const
{
    return "Koalite";
}