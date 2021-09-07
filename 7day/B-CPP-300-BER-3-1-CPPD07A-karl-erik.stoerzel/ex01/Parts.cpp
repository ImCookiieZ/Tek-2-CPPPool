/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

Parts::Parts(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

bool Parts::isFunctional() const
{
    return this->_functional;
}

std::string Parts::serial() const
{
    return this->_serial;
}

void Parts::informations() const
{
    std::cout << "\t[Parts] " << this->_type << " " << this->_serial << " status : ";
    if (this->_functional)
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
}

std::string Parts::getType() const
{
    return this->_type;
}

void Parts::setType(std::string type)
{
    this->_type = type;
}

Arms::Arms(std::string serial, bool functional) : Parts(serial, functional)
{
    this->setType("Arms");
}

Legs::Legs(std::string serial, bool functional) : Parts(serial, functional)
{
    this->setType("Legs");
}

Head::Head(std::string serial, bool functional) : Parts(serial, functional)
{
    this->setType("Head");
}
