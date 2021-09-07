/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Ratatouille.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_RATATOUILLE_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_RATATOUILLE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Ratatouille
{
private:
    std::ostringstream _ss;
public:
    Ratatouille() = default;
    Ratatouille(Ratatouille const &other);
    ~Ratatouille() = default;
    Ratatouille &operator=(const Ratatouille &rhs);

    Ratatouille &addVegetable(unsigned char c);
    Ratatouille &addCondiment(unsigned int i);
    Ratatouille &addSpice(double d);
    Ratatouille &addSauce(const std::string &str);

    std::string kooc();
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_RATATOUILLE_HPP
