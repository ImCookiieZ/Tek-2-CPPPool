/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** LittlePony.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_LITTLEPONY_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_LITTLEPONY_HPP

#include "Toy.hpp"

class LittlePony : public Toy
{
public:
    explicit LittlePony(std::string name = "nameless");
    void isTaken() const final ;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_LITTLEPONY_HPP
