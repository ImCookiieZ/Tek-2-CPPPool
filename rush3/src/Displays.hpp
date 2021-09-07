/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** Displays.hpp
*/

#ifndef RUSH3_DISPLAYS_HPP
#define RUSH3_DISPLAYS_HPP

#include <string>

class Displays
{
public:
    enum ChartType
    {
        BARCHART,
        PIECHART,
        DIAGRAM,
        NONE
    };
    ChartType Chart;
    virtual std::string GetString1() const = 0;
    virtual std::string GetString2() const = 0;
    virtual std::string GetString3() const = 0;
    virtual std::string GetName() const = 0;
    virtual float GetActual() = 0;
    virtual float GetMax() = 0;
    std::string ActualString;
    std::string MaxString;
    std::string Y_Name;
};

#endif //RUSH3_DISPLAYS_HPP
