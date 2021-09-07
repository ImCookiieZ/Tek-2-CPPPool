/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** SwapInfos.hpp
*/

#ifndef RUSH3_SWAPINFOS_HPP
#define RUSH3_SWAPINFOS_HPP

#include "Displays.hpp"
#include "getSystemData/SystemGetter.hpp"
class SwapInfos : public Displays
{
public:
    SwapInfos() : _swap(0, 0)
    {
        Chart = BARCHART;
        SetSwapUsed();
        MaxString = "FREE";
        ActualString = "USED";
        Y_Name = "gb";
    }
    ~SwapInfos() = default;
    void SetSwapUsed();
    std::string GetName() const override;
    std::string GetString1() const override;
    std::string GetString2() const override;
    std::string GetString3() const override;
    float GetActual() override;
    float GetMax() override;
private:
    Utilization _swap;
};

#endif //RUSH3_SWAPINFOS_HPP
