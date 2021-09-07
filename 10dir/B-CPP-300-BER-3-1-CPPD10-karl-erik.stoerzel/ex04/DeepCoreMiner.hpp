/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** DeepCoreMiner.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_DEEPCOREMINER_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"
#include <string>
#include <iostream>
#include "IAsteroid.hpp"

class DeepCoreMiner : IMiningLaser
{
public:
    void mine(IAsteroid * astro) override ;
    ~DeepCoreMiner() override;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_DEEPCOREMINER_HPP
