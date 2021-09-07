/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"

void Cesar::reset()
{
    _shifttime = 3;
}

void Cesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
        int base  = plainchar > 96 ? 97 : 65;
        plainchar = (char)(((int)plainchar - base + _shifttime) % 26 + base);
    }
    _shifttime = ++_shifttime % 26;
    std::cout << plainchar;
}

void Cesar::decryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
        int base  = plainchar > 96 ? 122 : 90;
        plainchar = (char)(((int)plainchar - base - _shifttime) % 26 + base);
    }
    _shifttime = ++_shifttime % 26;
    std::cout << plainchar;
}
