/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _home = EARTH;
    construct_base(length, width, name, maxWarp);
}

void Federation::Starfleet::Ship::construct_base(int length, int width, const std::string &name, short maxWarp)
{
    this->_maxWarp = maxWarp;
    this->_width = width;
    this->_length = length;
    this->_name = name;
    this->_captain = nullptr;

    std::cout << "The ";
    if (this->_inStarfleet)
        std::cout << "ship USS " << this->_name << " has been finished.";
    else
        std::cout << "independent ship " << this->_name << " just finished its construction.";
    std::cout  << std::endl << "It is " << this->_length << " m in length and " << this->_width
    << " m in ";
    std::cout << "width." << std::endl;
    if (this->_inStarfleet)
        std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    this->_location = this->_home;
    if (this->_inStarfleet)
        this->_shield = 100;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, bool
federation)
{
    this->_inStarfleet = federation;
    _home = EARTH;
    if (!this->_inStarfleet)
        _home = VULCAN;
    construct_base(length, width, name, maxWarp);
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *newCore)
{
    this->_core = newCore;
    if (this->_inStarfleet)
        std::cout << "USS " ;
    std::cout<< this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stable = "not set";
    if (this->_core)
        stable = this->_core->checkReactor()->isStable() ? "stable" : "unstable";
    if (this->_inStarfleet)
        std::cout << "USS ";
    std::cout << this->_name << ": The core is " << stable << " at the time." <<
    std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *newCaptain)
{
    std::string name = "[nullptr]";
    this->_captain = newCaptain;
    if (this->_captain)
        name = this->_captain->getName();
    std::cout << name << ": I'm glad to be the captain of the USS " << this->_name << "." <<
    std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
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

bool Federation::Starfleet::Ship::move(int warp)
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

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d == this->_location)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move()
{
    if (this->_location == this->_home)
        return false;
    if (!this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

Federation::Ship::Ship(int length, int width, std::string name) : Starfleet::Ship
(length, width, name, 1, false)
{}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

int Federation::Starfleet::Ship::getShield() const
{
    return this->_shield;
}

void Federation::Starfleet::Ship::setShield(const int &shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo() const
{
    return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(const int &torpedo)
{
    this->_photonTorpedo = torpedo;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}
