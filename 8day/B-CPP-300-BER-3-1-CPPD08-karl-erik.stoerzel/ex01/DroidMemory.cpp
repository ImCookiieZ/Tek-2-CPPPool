/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

size_t DroidMemory::getFingerprint() const
{
    return this->_fingerprint;
}

size_t DroidMemory::getExp() const
{
    return this->_exp;
}

void DroidMemory::setFingerprint(const size_t &newFingerprint)
{
    this->_fingerprint = newFingerprint;
}

void DroidMemory::setExp(const size_t &newExp)
{
    this->_exp = newExp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &addMemory)
{
    this->_exp += addMemory._exp;
    this->_fingerprint = this->_fingerprint ^ addMemory._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &addMemory) const
{
    addMemory._exp += this->_exp;
    addMemory._fingerprint = addMemory._fingerprint ^ this->_fingerprint;
    return addMemory;
}

DroidMemory::DroidMemory()
{
    this->_exp = 0;
    this->_fingerprint = random();
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &right)
{
    return (*this << right);
}

DroidMemory &DroidMemory::operator+=(const size_t &right)
{
    this->setExp(this->getExp() + right);
    this->setFingerprint(this->getFingerprint() ^ right);
    return *this;
}

DroidMemory &DroidMemory::operator+(const DroidMemory &right)
{
    auto *newMemory = new DroidMemory(*this);
    return (*newMemory << right);
}

DroidMemory &DroidMemory::operator+(const size_t &right)
{
    auto *newMemory = new DroidMemory(*this);
    newMemory->setExp(this->getExp() + right);
    newMemory->setFingerprint(this->getFingerprint() ^ right);
    return *newMemory;
}

std::ostream &operator<<(std::ostream &stream, const DroidMemory &memory)
{
    return (stream << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp());
}