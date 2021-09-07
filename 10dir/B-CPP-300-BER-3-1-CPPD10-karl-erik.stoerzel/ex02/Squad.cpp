/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Squad.cpp
*/

#include "Squad.hpp"
#include <iostream>
Squad::Squad()
{
    this->_nbUnits = 0;
    for (int i = 0; i < 201; i++)
        this->_units[i] = nullptr;
}

int Squad::getCount() const
{
    return _nbUnits;
}

ISpaceMarine *Squad::getUnit(int nb)
{
    if (nb < _nbUnits && nb >= 0)
        return _units[nb];
    return nullptr;
}

int Squad::push(ISpaceMarine *pushThis)
{
    if (pushThis)
    {
        for (int i = 0; i < 200; i++)
        {
            if (_units[i] == pushThis)
                break;
            else if (_units[i] == nullptr)
            {
                _units[i] = pushThis;
                _nbUnits++;
                break;
            }
        }
    }
    return _nbUnits;
}

Squad::Squad(Squad &copyFrom)
{
    this->_nbUnits = copyFrom._nbUnits;
     for (int i = 0; i < 201; i++)
         if (copyFrom._units[i])
            this->_units[i] = copyFrom._units[i]->clone();
         else
             this->_units[i] = nullptr;
}

Squad::~Squad()
{
    for (int i = 0; i < 201; i++)
        if (_units[i])
            delete this->_units[i];
}

Squad &Squad::operator=(const Squad &copyFrom)
{
    for (int i = 0; i < 200; i++)
        delete this->_units[i];
    this->_nbUnits = copyFrom._nbUnits;
    for (int i = 0; i < 201; i++)
        if (copyFrom._units[i])
            this->_units[i] = copyFrom._units[i]->clone();
        else
            this->_units[i] = nullptr;
    return *this;
}



//SpaceMarineArray::SpaceMarineArray(ISpaceMarine *newMarine)
//{
//    here = newMarine->clone();
//    next = nullptr;
//}
//
//int SpaceMarineArray::push(ISpaceMarine *pushThis)
//{
//    SpaceMarineArray *tmp = this;
//    while (tmp->next && tmp->here != pushThis)
//        tmp = tmp->next;
//    if (tmp->here != pushThis)
//        tmp->next = new SpaceMarineArray(pushThis);
//    else
//        return 0;
//    return 1;
//}
//
//ISpaceMarine *SpaceMarineArray::operator[](int pos) const
//{
//    const SpaceMarineArray *tmp = this;
//    for (int i = 0; i < pos && tmp; tmp = tmp->next)
//        if (tmp->here)
//            i++;
//    if (tmp)
//        return tmp->here;
//    return nullptr;
//}
//
//SpaceMarineArray::SpaceMarineArray(SpaceMarineArray const &copyFrom)
//{
//    this->here = copyFrom.here->clone();
//    this->next = copyFrom.next;
//    SpaceMarineArray *tmpFrom = copyFrom.next;
//    SpaceMarineArray *tmp = this->next;
//    while (tmpFrom)
//    {
//        this->here = tmpFrom->here->clone();
//        this->next = tmpFrom->next;
//        tmpFrom = tmpFrom->next;
//        tmp = tmp->next;
//    }
//}
//
//SpaceMarineArray::~SpaceMarineArray()
//{
//    delete this->here;
//    delete this->next;
//}

//ISpaceMarine *SpaceMarineArray::getUnit(int pos)
//{
//    SpaceMarineArray *tmp = this;
//    for (int i = 0; i < pos; i++)
//        tmp = tmp->next;
//    return tmp->here;
//}
