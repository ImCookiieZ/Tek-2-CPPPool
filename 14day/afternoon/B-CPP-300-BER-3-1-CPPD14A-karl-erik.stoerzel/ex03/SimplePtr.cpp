/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD14A_karl_erik_stoerzel
** File description:
** SimplePtr.cpp
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{
}

SimplePtr::~SimplePtr()
{
    delete _rawPtr;
}

BaseComponent *SimplePtr::get() const
{
    return _rawPtr;
}
SimplePtr::SimplePtr(SimplePtr const &other)
{
    _rawPtr = other._rawPtr;
}
SimplePtr &SimplePtr::operator=(SimplePtr const &other)
{
    _rawPtr = other._rawPtr;
    return *this;
}