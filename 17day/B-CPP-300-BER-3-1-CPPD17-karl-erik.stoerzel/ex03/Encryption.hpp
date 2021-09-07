/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** Encryption.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ENCRYPTION_HPP
#define B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ENCRYPTION_HPP

#include "Cesar.hpp"
#include "OneTime.hpp"
#include <algorithm>

class Encryption
{
public:
    static void encryptString(IEncryptionMethod &encryption_method,
        const std::string &toEncrypt);
    static void decryptString(IEncryptionMethod &decryption_method,
                              const std::string &toDecrypt);
};

#endif //B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_ENCRYPTION_HPP
