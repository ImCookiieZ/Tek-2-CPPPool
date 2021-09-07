/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii) : Toy(BUZZ, name, ascii)
{}

bool Buzz::speak(std::string statement)
{
    std::cout << getType() << ": ";
    return Toy::speak(statement);
}