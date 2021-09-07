/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = new Picture();
}

Toy::Toy(ToyType type, std::string name, std::string filepath)
{
    _type = type;
    _name = name;
    _picture = new Picture(filepath);
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string filepath)
{
    return _picture->getPictureFromFile(filepath);
}

std::string Toy::getAscii() const
{
    return _picture->data;
}
Toy::Toy(Toy const &from)
{
    _type = from._type;
    _name = from._name;
    _picture = new Picture(*from._picture);
}

Toy &Toy::operator=(const Toy &from)
{
    _type = from._type;
    _name = from._name;
    _picture = new Picture(*from._picture);
    return *this;
}
//Toy::~Toy() = default;