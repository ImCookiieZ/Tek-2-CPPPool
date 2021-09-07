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

//Toy::~Toy()
//{
//    delete _picture;
//}

std::ostream &operator<<(std::ostream &stream, Toy::ToyType type)
{
    switch (type)
    {
        case Toy::ToyType::BASIC_TOY:
            stream << "BASIC_TOY";
            break;
        case Toy::ToyType::WOODY:
            stream << "WOODY";
            break;
        case Toy::ToyType::ALIEN:
            stream << "ALIEN";
            break;
        case Toy::ToyType::BUZZ:
            stream<< "BUZZ";
            break;
    }
    return stream;
}

bool Toy::speak(std::string statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

Toy &Toy::operator<<(std::string picture)
{
    _picture->data = picture;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Toy toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return stream;
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