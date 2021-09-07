/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD14A_karl_erik_stoerzel
** File description:
** RefPtr.cpp
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr)
{
    _rawPtr = rawPtr;
}

RefPtr::RefPtr(const RefPtr &other)
{
    _rawPtr = other._rawPtr;
}

RefPtr &RefPtr::operator=(const RefPtr &other)
{
    _rawPtr = other._rawPtr;
    return *this;
}

RefPtr::~RefPtr()
{
    delete _rawPtr;
}

BaseComponent *RefPtr::get() const
{
    return _rawPtr;
}

