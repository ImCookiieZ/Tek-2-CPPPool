/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Buzz.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_BUZZ_HPP
#define B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_BUZZ_HPP

#include "Toy.hpp"

class Buzz : public Toy
{
private:
public:
    Buzz(std::string name, std::string ascii = "buzz.txt");

    bool speak(std::string statement) override;
    bool speak_es(std::string statement) override ;
};

#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_BUZZ_HPP
