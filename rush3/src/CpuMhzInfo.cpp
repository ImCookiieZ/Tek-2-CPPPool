//
// Created by hasan on 1/23/21.
//

#include "CpuMhzInfo.hpp"
#include "getSystemData/SystemGetter.hpp"
#include <sstream>

void CpuMhzInfo::SetIndex(int index) {
    _index = index;
}

void CpuMhzInfo::SetModelName() {
    _modelName = SystemGetter::GetCpuModel(_index);
}

void CpuMhzInfo::SetCpuMhz() {
    _cpuMhz = SystemGetter::GetCpuMHz(_index);
}

int CpuMhzInfo::GetIndex() const {
    return _index;
}

std::string CpuMhzInfo::GetModelName() const {
    return _modelName;
}

std::string CpuMhzInfo::GetCpuMhz() {
    SetCpuMhz();
    return std::to_string(_cpuMhz);
}

std::string CpuMhzInfo::GetName() const
{
    std::stringstream ss;
    ss << "CPU" << _index;
    return ss.str();
}

std::string CpuMhzInfo::GetString1() const
{
    std::stringstream ss;
    ss << "Actual: " << _cpuMhz << "MHz";
    return ss.str();
}

std::string CpuMhzInfo::GetString3() const
{
    return std::string();
}

std::string CpuMhzInfo::GetString2() const
{
    std::stringstream ss;
    ss << "processor: " << _modelName;
    return ss.str();
}

float CpuMhzInfo::GetActual()
{
    SetCpuMhz();
    return (float)_cpuMhz;
}

float CpuMhzInfo::GetMax()
{
    size_t start = _modelName.find("@ ") + 2;
    return std::stof(_modelName.substr(start, 4)) * 1000;
}

