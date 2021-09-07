/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Box.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_BOX_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_BOX_HPP

#include "Wrap.hpp"

class Box : public Wrap
{
public:
    Box();
    void wrapMeThat(Object &rfs, bool santa) final;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_BOX_HPP
