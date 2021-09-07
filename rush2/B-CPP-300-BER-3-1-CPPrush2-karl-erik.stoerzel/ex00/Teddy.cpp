/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Teddy.cpp
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string name) : Toy(name, "Teddy")
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}