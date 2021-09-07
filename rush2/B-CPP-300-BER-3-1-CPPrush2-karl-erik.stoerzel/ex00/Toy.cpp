/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy(std::string name, std::string type) : Object(type)
{
    _name = name;
}

std::string Toy::getName() const
{
    return _name;
}

std::ostream &operator<<(std::ostream &ostream, Toy const &toy)
{

    ostream << toy.getType() << " called: " << toy.getName() << std::endl;
    return ostream;
}