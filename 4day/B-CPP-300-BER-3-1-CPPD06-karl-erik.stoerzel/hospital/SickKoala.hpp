/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** SickKoala.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALA_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALA_HPP

#include <string>
#include <iostream>

class SickKoala
{
private:
    std::string name;
    void printMr();
    void printStrWithMr(std::string str);
public:
    explicit SickKoala(std::string name);
    ~SickKoala();
    void poke();
    bool takeDrug(std::string);
    void overDrive(std::string);
    std::string getName();
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALA_HPP