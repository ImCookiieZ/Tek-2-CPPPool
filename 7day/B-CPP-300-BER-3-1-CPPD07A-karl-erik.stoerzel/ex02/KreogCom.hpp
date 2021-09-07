/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** KreogCom.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KREOGCOM_HPP
#define B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KREOGCOM_HPP

#include <string>
#include <iostream>

class KreogCom
{
public :
    KreogCom(int x, int y, int serial);
    ~KreogCom();
    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom() const;
    void ping() const;
    void locateSquad() const;
private :
    const int m_serial = 0;
    int _serial;
    int _x;
    int _y;
    KreogCom *next;
    KreogCom *prev;
};

#endif //B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KREOGCOM_HPP
