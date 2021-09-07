/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaDoctorList.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTORLIST_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTORLIST_HPP

#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
private:
    KoalaDoctor *doctor;
    KoalaDoctorList *next;
    KoalaDoctorList *head;
    void setHeadToNext();
public:
    explicit KoalaDoctorList(KoalaDoctor *start);
    bool isEnd();
    void append(KoalaDoctorList *node);
    KoalaDoctor *getFromName(std::string name);
    KoalaDoctorList *remove(KoalaDoctorList *node);
    KoalaDoctorList *removeFromName(std::string name);
    KoalaDoctor *getContent();
    KoalaDoctorList *getNext();
    void dump();
    KoalaDoctorList *removeUntilLast();
    bool existsElement(KoalaDoctorList *element);
    KoalaDoctorList *GetHead();
    std::string getContentName();
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALADOCTORLIST_HPP