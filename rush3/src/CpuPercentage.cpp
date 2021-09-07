/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** CpuPercentage.cpp
*/

#include "CpuPercentage.hpp"
#include <sstream>
void CpuPercentageInfos::SetCpuProcentage()
{
    _procentage = SystemGetter::GetCpuUsage(_index);
}

std::string CpuPercentageInfos::GetCpuProcentage()
{
    SetCpuProcentage();
    return std::to_string(_procentage);
}

std::string CpuPercentageInfos::GetName() const
{
    std::stringstream ss;
    ss << "CPU" << _index;
    return ss.str();
}

std::string CpuPercentageInfos::GetString1() const
{
    std::stringstream ss;
    ss << "Actual: " << _procentage << "%";
    return ss.str();
}

std::string CpuPercentageInfos::GetString2() const
{
    std::stringstream ss;
    ss << "processor: " << _modelName;
    return ss.str();
}

float CpuPercentageInfos::GetActual()
{
    SetCpuProcentage();
    return _procentage;
}

float CpuPercentageInfos::GetMax()
{
    return 100;
}
