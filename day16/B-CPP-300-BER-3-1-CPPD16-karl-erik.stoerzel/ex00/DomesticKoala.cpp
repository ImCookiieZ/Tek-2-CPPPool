/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** DomesticKoala.cpp
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action) : _allActions(257)
{
    _action = action;
}

DomesticKoala::DomesticKoala(const DomesticKoala &from)
{
    _action = from._action;
    _allActions = from._allActions;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &from)
{
    _action = from._action;
    _allActions = from._allActions;
    return *this;
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getAction() const
{
    return &_allActions;
}

void DomesticKoala::learnAction(unsigned char command, DomesticKoala::methodPointer_t action)
{
    _allActions[command] = action;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    methodPointer_t func = _allActions[command];
    if (func)
        (_action.*func)(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &from)
{
    _action = from;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    _allActions[command] = nullptr;
}
