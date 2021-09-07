/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Ratatouille.cpp
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille(const Ratatouille &other)
{
    _ss << other._ss.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &rhs)
{
    _ss.str("");
    _ss << rhs._ss.str();
    return *this;
}

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
    _ss << c;
    return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int i)
{
    _ss << i;
    return *this;
}

Ratatouille &Ratatouille::addSpice(double d)
{
    _ss << d;
    return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &str)
{
    _ss << str;
    return *this;
}

std::string Ratatouille::kooc()
{
    return _ss.str();
}
