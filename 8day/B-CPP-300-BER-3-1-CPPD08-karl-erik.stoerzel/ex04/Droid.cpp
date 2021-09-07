/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(const std::string& id)
{
    this->_id = id;
    this->talk("Activated");
    std::string *tmp = new std::string ("Standing by");
    this->setStatus(tmp);
    delete tmp;
    this->_battleData = new DroidMemory();
}

Droid::Droid(const Droid &copyFrom)
{
    this->_id = copyFrom._id;
    this->talk("Activated, Memory Dumped");
    this->setStatus(new std::string (*copyFrom._status));
    this->_battleData = new DroidMemory();
}

Droid &Droid::operator=(const Droid &assignWith)
{
    this->_id = assignWith._id;
    delete this->_status;
    this->_status = new std::string(*assignWith._status);
    return *this;
}

bool Droid::operator==(const Droid &compareWith) const
{
    return (*this->_status == *compareWith._status);
}

bool Droid::operator!=(const Droid &compareWith) const
{
    return (*this->_status != *compareWith._status);
}

std::string Droid::getId() const
{
    return this->_id;
}

size_t Droid::getEnergy() const
{
    return this->_energy;
}

size_t Droid::getAttack() const
{
    return this->Attack;
}

size_t Droid::getToughness() const
{
    return this->Toughness;
}

std::string *Droid::getStatus() const
{
    return this->_status;
}

void Droid::setId(const std::string& id)
{
    this->_id = id;
}

void Droid::setEnergy(const size_t& energy)
{
    if (energy > 100)
        return;
    this->_energy = energy;
}

void Droid::setStatus(const std::string *status)
{
    delete this->_status;
    this->_status = new std::string(*status);
}

Droid::~Droid()
{
    this->talk("Destroyed");
    delete this->_status;
    delete this->_battleData;
}

void Droid::talk(const std::string& sentence) const
{
    std::cout << "Droid '" << this->_id << "' " << sentence;
    std::cout << std::endl;
}

size_t &Droid::operator<<(size_t &value)
{

    if (100 - this->_energy >= value)
    {
        this->_energy += value;
        value = 0;
    }
    else
    {
        value -= this->_energy;
        this->_energy = 100;
    }
    return value;
}

Droid &Droid::operator<<(Droid &value)
{
    if (100 - this->_energy >= value.getEnergy())
    {
        this->_energy += value.getEnergy();
        value.setEnergy(0);
    }
    else
    {
        this->_energy = 100;
        value.setEnergy(100 - this->_energy);
    }
    return value;
}

std::ostream &operator<<(std::ostream &stream, const Droid &thisDroid)
{
    stream << "Droid '" << thisDroid.getId() << "', " << *thisDroid.getStatus() << ", " <<
    thisDroid.getEnergy();
    return stream;
}

DroidMemory *Droid::getBattleData() const
{
    return this->_battleData;
}

void Droid::setBattleData(const DroidMemory *setTo)
{
    delete this->_battleData;
    this->_battleData = new DroidMemory(*setTo);
}

bool Droid::operator()(const std::string *task, size_t exp)
{
    std::string *tmp = nullptr;
    bool ret = false;
    if (this->_energy <= 10)
    {
        _energy = 0;
        tmp = new std::string("Battery Low");
        setStatus(tmp);
    }
    else
    {
        _energy -= 10;
        if (*this->_battleData >= exp)
        {
            tmp = new std::string(*task + " - Completed!");
            setStatus(tmp);
            this->_battleData->addExp(exp / 2);
            ret = true;
        }
        else
        {
            tmp = new std::string(*task + " - Failed!");
            setStatus(tmp);
            this->_battleData->addExp(exp);
        }
    }
    delete tmp;
    return ret;
}
