/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** IAsteroid.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_IASTEROID_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_IASTEROID_HPP

#include "IMiningLaser.hpp"
#include <string>

class IAsteroid
{
public :
    virtual ~IAsteroid () {}
    virtual std::string beMined (IMiningLaser *) const = 0;
    virtual std::string getName () const = 0;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_IASTEROID_HPP
