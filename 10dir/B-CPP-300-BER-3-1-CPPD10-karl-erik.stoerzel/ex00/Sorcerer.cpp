/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Sorcerer.cpp
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_name = name;
    this->_title = title;
    this->talk("is born!");
}

Sorcerer::~Sorcerer()
{
    this->talk("is dead. Consequences will never be the same!");
}

void Sorcerer::talk(std::string sentence) const
{
    std::cout << this->_name << ", " << this->_title << ", " << sentence << std::endl;
}

std::string Sorcerer::getName() const
{
    return this->_name;
}

std::string Sorcerer::getTitle() const
{
    return this->_title;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &stream, const Sorcerer &sorcerer)
{
    stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like " <<
        "ponies!" << std::endl;
    return stream;
}