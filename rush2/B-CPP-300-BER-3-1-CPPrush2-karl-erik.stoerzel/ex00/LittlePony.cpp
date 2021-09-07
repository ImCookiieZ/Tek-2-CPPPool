/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** LittlePony.cpp
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string name) : Toy(name, "LittlePony")
{
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}

