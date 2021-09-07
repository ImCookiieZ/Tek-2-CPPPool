/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** OneTime.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ONETIME_HPP
#define B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ONETIME_HPP

#include "IEncryptionMethod.hpp"
#include <iostream>
#include <utility>

class OneTime : public IEncryptionMethod
{
private:
    std::string _key;
    size_t _index = 0;
public:
    explicit OneTime(std::string const &key);
    void encryptChar(char plainchar) override ;
    void decryptChar(char plainchar) override ;
    void reset() override;
};
#endif //B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ONETIME_HPP
