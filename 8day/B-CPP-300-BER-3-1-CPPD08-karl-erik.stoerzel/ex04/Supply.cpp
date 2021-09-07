/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Supply.cpp
*/

#include "Supply.hpp"

Supply::operator size_t() const
{
    return this->_amount;
}

Supply::Supply(Supply::Types type, size_t amount)
{
    this->_type = type;
    this->_amount = amount;
    this->_wrecks = nullptr;
}

Droid *&Supply::operator*()
{
    return this->_wrecks[this->_curWreck];
}

Supply::Supply(Supply::Types type, size_t amount, Droid **&wracks)
{
    this->_type = type;
    this->_amount = amount;
    this->_wrecks = wracks;
}

Supply &Supply::operator!()
{
    if (this->_wrecks)
    {
//        delete this->_wrecks;
        for (size_t i = 0; i < this->_amount; i++)
            delete this->_wrecks[i];
        delete[] this->_wrecks;
    }
    this->_wrecks = nullptr;
    this->_amount = 0;
    return *this;
}

bool Supply::operator==(Supply::Types const type) const
{
    return this->_type == type;
}

bool Supply::operator!=(Supply::Types const type) const
{
    return this->_type != type;
}

Supply::~Supply()
{
    delete this->_wrecks;
}

std::string Supply::getType() const
{
    if (this->_type == 1)
        return "Iron";
    else if (this->_type == 2)
        return "Silicon";
    else
        return "Wreck";
}

Supply &Supply::operator++()
{
    if (++this->_curWreck >= this->_amount)
        this->_curWreck = 0;
    return (*this);
}

Supply &Supply::operator--()
{
    if (this->_curWreck == 0)
        this->_curWreck = this->_amount - 1;
    else
        this->_curWreck -= 1;
    return (*this);
}

Droid *Supply::operator->() const
{
    return this->_wrecks[this->_curWreck];
}

void Supply::giveInformation(std::ostream &stream) const
{
    if (this->_wrecks && this->_amount > 0)
    {
        stream << std::endl;
        for (size_t i = 0; i < this->_amount; i++)
        {
            stream << *this->_wrecks[i];
            if (i < this->_amount - 1)
                stream << std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, Supply &sub)
{
    stream << "Supply : " << (size_t)sub << ", " << sub.getType();
    sub.giveInformation(stream);
    return stream;
}