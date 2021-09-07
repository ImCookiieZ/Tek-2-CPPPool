/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(std::string const name, const std::string ascii) : Toy(WOODY, name,
    ascii)
{}

bool Woody::speak(std::string statement)
{
    std::cout << getType() << ": ";
    return Toy::speak(statement);
}
