/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaNurseList.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSELIST_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSELIST_HPP

#include "KoalaNurse.hpp"
#include <iostream>

class KoalaNurseList
{
private:
    KoalaNurse *koalaNurse;
    KoalaNurseList *next;
    KoalaNurseList *head;
    void setHeadToNext();
public:
    explicit KoalaNurseList(KoalaNurse *start);
    bool isEnd();
    void append(KoalaNurseList *node);
    KoalaNurse *getFromID(int ID);
    KoalaNurseList *remove(KoalaNurseList *node);
    KoalaNurseList *removeFromID(int ID);
    KoalaNurse *getContent();
    KoalaNurseList *getNext();
    void dump();
    KoalaNurseList *removeUntilLast();
    bool existsElement(KoalaNurseList *element);
    KoalaNurseList *getHead();
    void printContentID();
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSELIST_HPP