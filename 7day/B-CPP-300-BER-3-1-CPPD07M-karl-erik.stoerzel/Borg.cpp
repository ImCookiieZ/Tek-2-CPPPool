/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** Borg.cpp
*/

#include "Borg.hpp"

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    bool stable = true;
    if (this->_core)
    {
        if (this->_core->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }
    else
    {
        std::cout << "No core available!" << std::endl;
    }
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp > this->_maxWarp)
        return false;
    if (d == this->_location)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(int warp)
{
    if (warp > this->_maxWarp)
        return false;
    if (this->_home == this->_location)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Borg::Ship::move(Destination d)
{
    if (d == this->_location)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move()
{
    if (this->_location == this->_home)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

Borg::Ship::Ship()
{
    this->_home = UNICOMPLEX;
    this->_side = 300;
    this->_maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally."
    << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." <<
    std::endl;
    std::cout << "Resistance is futile." << std::endl;
    this->_location = this->_home;
}
