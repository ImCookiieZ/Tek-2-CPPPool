/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string& serial)
{
    this->_serial = serial;
}

void KoalaBot::setParts(const Parts &part)
{
    if (part.getType() == "Arms")
        this->_arms = (Arms&)part;
    else if (part.getType() == "Legs")
        this->_legs = (Legs&)part;
    else if (part.getType() == "Head")
        this->_head = (Head&)part;
}

void KoalaBot::swapParts(Arms &part)
{
    Arms tmp = part;
    part = this->_arms;
    this->_arms = tmp;
}

void KoalaBot::swapParts(Legs &part)
{
    Legs tmp = part;
    part = this->_legs;
    this->_legs = tmp;
}

void KoalaBot::swapParts(Head &part)
{
    Head tmp = part;
    part = this->_head;
    this->_head = tmp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const
{
    return this->_head.isFunctional() && this->_legs.isFunctional() && this->_arms.isFunctional();
}
