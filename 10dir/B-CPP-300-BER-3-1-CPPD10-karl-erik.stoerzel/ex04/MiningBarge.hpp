/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** MiningBarge.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MININGBARGE_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MININGBARGE_HPP

#include "IMiningLaser.hpp"

class MiningBarge
{
private:
    IMiningLaser *_weapons[4]{};
public :
    MiningBarge();
    ~MiningBarge();
    void equip(IMiningLaser *laser);
    void mine(IAsteroid *asteroid)const ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MININGBARGE_HPP
