/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** ToyStory.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOYSTORY_HPP
#define B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOYSTORY_HPP

#include "Toy.hpp"

typedef bool (Toy::*func)(std::string param) ;

class ToyStory
{
public:
    static bool tellMeAStory(std::string filepath, Toy toy1, func func1, Toy toy2, func func2);
//    static std::string getRestOfFile(std::ifstream file, int line);
};

#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOYSTORY_HPP
