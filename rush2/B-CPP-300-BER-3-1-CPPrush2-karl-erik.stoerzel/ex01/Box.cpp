/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Box.cpp
*/

#include "Box.hpp"

Box::Box() : Wrap("Box")
{
}

void Box::wrapMeThat(Object &ref, bool santa)
{
    if (_isOpen)
        Wrap::wrapMeThat(ref, santa);
    else
        std::cerr << "Box is closed" << std::endl;
}

