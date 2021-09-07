/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaDoctor.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTOR_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTOR_HPP

#include <string>
#include <iostream>
#include "SickKoala.hpp"

class KoalaDoctor
{
private:
    void printStrWithDoctor(std::string str) const;
    std::string name;
    bool working = false;
public:
    explicit KoalaDoctor(std::string name);
//    ~KoalaDoctor();
    void diagnose(SickKoala *patient);
    void timeCheck();
    std::string getName();
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTOR_HPP