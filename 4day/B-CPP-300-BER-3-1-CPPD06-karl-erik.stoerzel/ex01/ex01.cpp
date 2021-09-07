/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** ex01.cpp
*/

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

void cald_and_print(std::string type, float f, const std::string &second)
{
    const std::string fahrenheit  = "Fahrenheit";
    const std::string celsius = "Celsius";float res = 0;

    if (second.find(celsius) != std::string::npos) {
        res = 9.0f / 5.0f * f + 32.0f;
        type = fahrenheit;
    }
    else if (second.find(fahrenheit) != std::string::npos)
    {
        res = 5.0f / 9.0f * (f - 32.0f);
        type = celsius;
    }
    std::cout << std::setw(16) << std::setprecision(3) << std::fixed << res << std::setw(16) <<
    type << std::endl;
}

int main(int ac, char **av)
{
    std::string type;
    std::string str;
    std::string deliminator = " ";
    size_t pos = 0;
    float f = 0;
    getline(std::cin, str);

    std::string first;
    std::string second;
    pos = str.find(deliminator);
    if (pos == std::string::npos)
        return (84);
    first = str.substr(0, pos);
    second = str.erase(0, pos + 1);
    f = std::stof(first);
    cald_and_print(type, f, second);
    return (0);
}