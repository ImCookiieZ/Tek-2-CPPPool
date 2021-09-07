/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** RamInfos.cpp
*/

#include "RamInfos.hpp"
#include <sstream>

std::string RamInfos::GetName() const
{
    return "RAM";
}

void RamInfos::SetRamUsed()
{
    _ram = SystemGetter::GetRamUtilization();
}

std::string RamInfos::GetString1() const
{
    std::stringstream ss;
    ss << "Max ram: " << _ram.Max << "gb";
    return ss.str();
}

std::string RamInfos::GetString2() const
{
    std::stringstream ss;
    ss << "Actual used: " << _ram.Actual << "gb";
    return ss.str();
}

std::string RamInfos::GetString3() const
{
    std::stringstream ss;
    ss << _ram.GetPercentage() << "%";
    return ss.str();
}

float RamInfos::GetActual()
{
    SetRamUsed();
    return _ram.Actual;
}

float RamInfos::GetMax()
{
    SetRamUsed();
    return _ram.Max;
}
