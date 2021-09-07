/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** SIckKoalaList.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALALIST_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALALIST_HPP

#include "SickKoala.hpp"

class SickKoalaList
{
private:
    SickKoala *koala;
    SickKoalaList *next;
    SickKoalaList *head;
    void setHeadToNext();
public:
    explicit SickKoalaList(SickKoala *start);
    bool isEnd();
    void append(SickKoalaList *node);
    SickKoala *getFromName(std::string name);
    SickKoalaList *remove(SickKoalaList *node);
    SickKoalaList *removeFromName(std::string name);
    SickKoala *getContent();
    SickKoalaList *getNext();
    void dump();
    SickKoalaList *removeUntilLast();
    bool existsElement(SickKoalaList *element);
    SickKoalaList *getHead();
    std::string getContentName();
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_SICKKOALALIST_HPP