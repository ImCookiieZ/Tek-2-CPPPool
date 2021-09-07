/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Toy.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TOY_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TOY_HPP

#include "Object.hpp"

class Toy : public Object
{
    std::string _name;
public:
    explicit Toy(std::string name = "nameless", std::string type = "Toy");
    std::string getName() const;
};

std::ostream &operator<<(std::ostream &ostream, Toy const &toy);

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TOY_HPP
