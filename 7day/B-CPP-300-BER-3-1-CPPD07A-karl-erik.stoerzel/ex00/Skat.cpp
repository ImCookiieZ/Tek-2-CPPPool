/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

Skat::Skat(const std::string &name)
{
    this->_name = name;
}

Skat::Skat(int stimPaks)
{
    this->_stimPaks = stimPaks;
}

int &Skat::stimPaks()
{
    return (this->_stimPaks);
}

const std::string &Skat::name()
{
    return this->_name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->_stimPaks < number)
        std::cout << "Don't be greedy" << std::endl;
    else
    {
        stock += number;
        this->_stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    this->_stimPaks += number;
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks()
{
    if (!this->_stimPaks)
        std::cout << "Mediiiiiic" << std::endl;
    else
    {
        this->_stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks;
    std::cout << " stimpaks remaining sir!" << std::endl;
}

Skat::Skat()
= default;
