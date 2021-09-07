/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** KreogCom.cpp
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
{
    this->_x = x;
    this->_y = y;
    this->_serial = serial;
    this->next = nullptr;
    this->prev = nullptr;
    std::cout << "KreogCom " << this->_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (this->prev)
        this->prev->next = this->next;
    if (this->next)
        this->next->prev = this->prev;
    std::cout << "KreogCom " << this->_serial << " shutting down" <<std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newKreog = new KreogCom(x, y, serial);
    KreogCom *tmp = nullptr;
    if (!this->next)
    {
        this->next = newKreog;
    }
    else
    {
        tmp = this->next;
        this->next = newKreog;

        newKreog->next = tmp;
        tmp->prev = newKreog;
    }
    newKreog->prev = this;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = nullptr;
    if (!this->next)
        return;
    tmp = this->next;
    this->next = this->next->next;
    delete tmp;
}

KreogCom *KreogCom::getCom() const
{
    return this->next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " <<
    this->_serial << " currently at " <<
    this->_x << " "
    << this->_y
    << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->next;
    while (tmp)
    {
        tmp->ping();
        tmp = tmp->next;
    }
    this->ping();
}
