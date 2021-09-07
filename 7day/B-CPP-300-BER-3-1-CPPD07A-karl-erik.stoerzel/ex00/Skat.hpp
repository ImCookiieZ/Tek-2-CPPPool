/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Skat.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_SKAT_HPP
#define B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_SKAT_HPP

#include <string>
#include <iostream>

class Skat
{
private:
    std::string _name = "bob";
    int _stimPaks = 15;
public :
    Skat(const std::string &name, int stimPaks);
    explicit Skat(const std::string &name);
    explicit Skat(int stimPaks);
    Skat();
    int &stimPaks();
    const std::string &name();
    void shareStimPaks(int number, int &stock );
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
};

#endif //B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_SKAT_HPP
