//
// Created by hasan on 1/23/21.
//

#ifndef B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_CPUINFO_HPP
#define B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_CPUINFO_HPP

#include <string>
#include "Displays.hpp"
#include <iostream>
class CpuMhzInfo : public Displays
{
public:
    CpuMhzInfo(int index)
    {
        Chart = DIAGRAM;
        SetIndex(index);
        SetModelName();
        SetCpuMhz();
        ActualString = "CURRENT";
        MaxString = "AVAILABLE";
        Y_Name = "MHz";
    }
    ~CpuMhzInfo() = default;
    void SetIndex(int index);
    void SetModelName();
    void SetCpuMhz();
    int GetIndex() const;
    std::string GetModelName() const;
    std::string GetCpuMhz();
    std::string GetName() const override;
    std::string GetString1() const override;
    std::string GetString2() const override;
    std::string GetString3() const override;
    float GetActual() override;
    float GetMax() override;
private:
    int _index{};
    std::string _modelName;
    int _cpuMhz{};
};

#endif //B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_CPUINFO_HPP
