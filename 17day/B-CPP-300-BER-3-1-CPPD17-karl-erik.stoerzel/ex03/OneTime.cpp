/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** OneTime.cpp
*/

#include <algorithm>
#include <sstream>
#include "OneTime.hpp"

OneTime::OneTime(std::string const &key)
{
    std::stringstream ss;
    for (size_t i = 0; i < key.length(); i++)
        ss << (char)(std::tolower(key[i]) - 97);
    _key = ss.str();
    _index = 0;
}

void OneTime::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
        int base  = plainchar > 96 ? 97 : 65;
        plainchar = (char)(((int)plainchar - base + _key[_index]) % 26 + base);
    }
    _index = ++_index % _key.length();
    std::cout << plainchar;
}

void OneTime::decryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
        int base  = plainchar > 96 ? 122 : 90;
        plainchar = (char)(((int)plainchar - base - _key[_index]) % 26 + base);
    }
    _index = ++_index % _key.length();
    std::cout << plainchar;
}

void OneTime::reset()
{
    _index = 0;
}
