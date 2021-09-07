/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** Cesar.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CESAR_HPP
#define B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CESAR_HPP

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : public IEncryptionMethod
{
private:
    int _shifttime = 3;
public:
    Cesar() = default;
    ~Cesar() override = default;
    void encryptChar(char plainchar) override ;
    void decryptChar(char plainchar) override ;
    void reset() override;
};

#endif //B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CESAR_HPP
