/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** ex03.cpp
*/

#include "SickKoala.hpp"

void SickKoala::printMr()
{
    std::cout << "Mr." << this->name << ": ";
}

void SickKoala::printStrWithMr(std::string str)
{
    this->printMr();
    std::cout << str << std::endl;
}

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    this->printStrWithMr("Kreooogg!! I'm cuuuured!");
    this->name = "";
}

void SickKoala::poke()
{
    this->printStrWithMr("Gooeeeeerrk!!");
}

bool SickKoala::takeDrug(std::string str)
{
    if (str == "Mars")
    {
        this->printStrWithMr("Mars, and it kreogs!");
        return true;
    }
    if (str == "Kinder")
    {
        this->printStrWithMr("There is a toy inside!");
        return true;
    }
    this->printStrWithMr("Goerkreog!");
    return (false);
}

std::string SickKoala::getName()
{
    return this->name;
}

void SickKoala::overDrive(std::string str)
{
    std::size_t pos = 0;
    pos = str.find("Kreog!", pos);
    while (pos != std::string::npos)
    {
        str.replace(pos, 6, "1337!");
        pos = str.find("Kreog!", pos);
    }
    this->printStrWithMr(str);
}