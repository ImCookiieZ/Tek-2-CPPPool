/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** Encryption.cpp
*/

#include "Encryption.hpp"

void Encryption::encryptString(IEncryptionMethod &encryption_method, const std::string &toEncrypt)
{
    encryption_method.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(),[&](const char &c){encryption_method.encryptChar(c);});
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &decryption_method, const std::string &toDecrypt)
{
    decryption_method.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(),[&](const char &c){decryption_method.decryptChar(c);});
    std::cout << std::endl;
}
