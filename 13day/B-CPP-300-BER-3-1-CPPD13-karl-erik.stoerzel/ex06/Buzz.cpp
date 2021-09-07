/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii) : Toy(BUZZ, name, ascii)
{
    Toy::setSp(true);
}

bool Buzz::speak(std::string statement)
{
    std::cout << getType() << ": ";
    return Toy::speak(statement);
}

bool Buzz::speak_es(std::string statement)
{
    if (getSp())
    {
        std::cout << getType() << ": ";
        Toy::speak_es(statement);
    }
    else
        _error.type = Error::SPEAK;
    return getSp();
}
