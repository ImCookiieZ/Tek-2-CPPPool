/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** CpuPercentage.hpp
*/

#ifndef RUSH3_CPUPERCENTAGE_HPP
#define RUSH3_CPUPERCENTAGE_HPP

#include "Displays.hpp"
#include "getSystemData/SystemGetter.hpp"
class CpuPercentageInfos : public Displays
{
public:
    CpuPercentageInfos(int index)
    {
        Chart = PIECHART;
        _index = index;
        _modelName = SystemGetter::GetCpuModel(index);
        SetCpuProcentage();
        ActualString = "USED";
        MaxString = "UNUSED";
        Y_Name = "percentage";
    }
    ~CpuPercentageInfos() = default;
    void SetCpuProcentage();
    std::string GetCpuProcentage();
    std::string GetName() const override;
    std::string GetString1() const override;
    std::string GetString2() const override;
    std::string GetString3() const override{return "";};
    float GetActual() override;
    float GetMax() override;
private:
    int _index{};
    std::string _modelName;
    float _procentage{};
};

#endif //RUSH3_CPUPERCENTAGE_HPP
