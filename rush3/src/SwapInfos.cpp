/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** SwapInfos.cpp
*/

#include "SwapInfos.hpp"
#include <sstream>

std::string SwapInfos::GetName() const
{
    return "Swap";
}

void SwapInfos::SetSwapUsed()
{
    _swap = SystemGetter::GetSwapUtilization();
}

std::string SwapInfos::GetString1() const
{
    std::stringstream ss;
    ss << "Max Swap: " << _swap.Max << "gb";
    return ss.str();
}

std::string SwapInfos::GetString2() const
{
    std::stringstream ss;
    ss << "Actual used: " << _swap.Actual << "gb";
    return ss.str();
}

std::string SwapInfos::GetString3() const
{
    std::stringstream ss;
    ss << _swap.GetPercentage() << "gb";
    return ss.str();
}

float SwapInfos::GetActual()
{
    return _swap.Actual;
}

float SwapInfos::GetMax()
{
    return _swap.Max;
}
