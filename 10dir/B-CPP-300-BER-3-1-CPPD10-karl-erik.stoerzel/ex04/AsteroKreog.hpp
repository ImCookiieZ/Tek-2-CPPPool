/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AsteroKreog.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASTEROKREOG_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASTEROKREOG_HPP

#include "IAsteroid.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"

class AsteroKroeg : IAsteroid
{
public:
    ~AsteroKroeg() override;
    std::string getName () const override ;
    std::string beMined (IMiningLaser *laser) const override ;

    std::string beMined(DeepCoreMiner *laser) const;

    std::string beMined(StripMiner *laser) const;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_ASTEROKREOG_HPP
