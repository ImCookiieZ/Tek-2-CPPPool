/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** RamInfos.hpp
*/

#ifndef RUSH3_RAMINFOS_HPP
#define RUSH3_RAMINFOS_HPP

#include "Displays.hpp"
#include "getSystemData/SystemGetter.hpp"
class RamInfos : public Displays
{
public:
    RamInfos() : _ram(0, 0)
    {
        Chart = BARCHART;
        SetRamUsed();
        MaxString = "FREE";
        ActualString = "USED";
        Y_Name = "gb";
    }
    ~RamInfos() = default;
    void SetRamUsed();
    std::string GetName() const override;
    std::string GetString1() const override;
    std::string GetString2() const override;
    std::string GetString3() const override;
    float GetActual() override;
    float GetMax() override;
private:
    Utilization _ram;
};

#endif //RUSH3_RAMINFOS_HPP
