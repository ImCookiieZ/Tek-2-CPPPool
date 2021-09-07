/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Carrier.cpp
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string id) : _id(id), _energy(300), _attack(100), _toughness(90)
{
    this->_droids = new Droid*[5];
    for (int i = 0; i < 5; i++)
        this->_droids[i] = nullptr;
}

Carrier &Carrier::operator<<(Droid *&addDroid)
{
    int i = 0;
    if (!addDroid)
        return *this;
    for (; i < 5 && this->_droids[i] && this->_droids[i] != addDroid; i++);
    if (i < 5)
    {
        if (this->_droids[i] == addDroid)
            return *this;
        this->_droids[i] = addDroid;
        addDroid = nullptr;
    }
    return *this;
}

size_t Carrier::calcSpeed() const
{
    size_t tmp = 0;
    size_t passengers = 0;
    passengers = getPassengers();
    if (passengers > 0)
    {
        tmp = 100;
        tmp -= passengers * 10;
    }
    else
        tmp = 0;
    return tmp;
}

size_t Carrier::getPassengers() const
{
    size_t passengers = 0;
    for (size_t i = 0; i < 5; i++)
        if (_droids[i])
            passengers++;
    return passengers;
}

Droid *&Carrier::operator[](int position) const
{
    return this->_droids[position];
}

size_t Carrier::getSpeed() const
{
    return calcSpeed();
}

size_t Carrier::getEnergy() const
{
    return this->_energy;
}

size_t Carrier::getAttack() const
{
    return this->_attack;
}

size_t Carrier::getToughness() const
{
    return this->_toughness;
}

std::string Carrier::getId() const
{
    return this->_id;
}

void Carrier::setId(const std::string &id)
{
    this->_id = id;
}

void Carrier::setEnergy(const size_t &energy)
{
    this->_energy = energy;
}

Carrier &Carrier::operator>>(Droid *&removeDroid)
{
    int i = 0;
    for (; i < 5 && !this->_droids[i]; i++);
    if (i != 5)
    {
        removeDroid = this->_droids[i];
        this->_droids[i] = nullptr;
    }
    return *this;
}

Carrier &Carrier::operator~()
{
    return *this;
}

Carrier &Carrier::operator<<(size_t &energy)
{
    if (this->_energy < 600)
    {
        if (600 - this->_energy < energy)
        {
            size_t rem = 600 - this->_energy;
            this->_energy += rem;
            energy -= rem;
        }
        else
        {
            this->_energy += energy;
            energy = 0;
        }
    }
    return *this;
}

bool Carrier::operator()(int x, int y)
{
    size_t energyNeeded = (std::abs(x) + std::abs(y)) * (10 + this->getPassengers());
    if (energyNeeded < this->_energy)
    {
        this->_energy -= energyNeeded;
        if (getSpeed() != 0)
            return true;
    }
    return false;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++)
    {
        delete this->_droids[i];
    }
}

std::ostream &operator<<(std::ostream &ostream, const Carrier &carrier)
{
    ostream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        ostream << "[" << i << "] : ";
        if (carrier[i])
            ostream << *carrier[i];
        else
            ostream << "Free";
        ostream << std::endl;
    }
    ostream << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return ostream;
}