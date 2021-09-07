/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool newStability)
{
    this->_stability = newStability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *newReactor)
{
    this->_coreReactor = newReactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}
