/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Phaser.cpp
*/

#include "Phaser.hpp"
#include "Sounds.hpp"

Phaser::Phaser(int maxAmmo, Phaser::AmmoType type)
{
    this->_maxAmmo = maxAmmo;
    this->_defaultType = type;
    this->firstBullet = nullptr;
    this->lastBullet = nullptr;
    this->_curAmmo = 0;
    for (int i = 0; i < this->_maxAmmo; i++)
        this->addAmmo(this->_defaultType);
}

void Phaser::fire()
{
    MyAmmo *tmp = this->firstBullet;
    if (this->_curAmmo == Empty)
    {
        std::cout << "Clip empty, please reload" << std::endl;
    }
    else
    {
        if (this->firstBullet->type == REGULAR)
            std::cout << Sounds::Regular << std::endl;
        if (this->firstBullet->type == PLASMA)
            std::cout << Sounds::Plasma << std::endl;
        if (this->firstBullet->type == ROCKET)
            std::cout << Sounds::Rocket << std::endl;
        this->_curAmmo--;
        this->firstBullet = this->firstBullet->next;
        delete tmp;
    }
    if (this->_curAmmo == Empty)
        this->lastBullet = nullptr;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    deleteAllBullets();
    this->firstBullet = nullptr;
    this->lastBullet = nullptr;
    this->_curAmmo = 0;
    for (int i = 0; i < this->_maxAmmo; i++)
        this->addAmmo(this->_defaultType);
}

void Phaser::ejectClip()
{
    deleteAllBullets();
    this->firstBullet = nullptr;
    this->lastBullet = nullptr;
    this->_curAmmo = Empty;
}

void Phaser::changeType(Phaser::AmmoType newType)
{
    std::string thisType;
    if (newType == REGULAR)
        thisType = "regular";
    if (newType == PLASMA)
        thisType = "plasma";
    if (newType == ROCKET)
        thisType = "rocket";
    std::cout << "Switching ammo to type: " << thisType << std::endl;
    this->_defaultType = newType;
}

void Phaser::addAmmo(Phaser::AmmoType type)
{
    if (this->_maxAmmo > this->_curAmmo)
    {
        MyAmmo *newBullet = new MyAmmo(type);
        if (this->lastBullet)
            this->lastBullet->next = newBullet;
        else
        {
            this->firstBullet = newBullet;
        }
        this->lastBullet = newBullet;
        this->_curAmmo++;
    }
    else
        std::cout << "Clip full" << std::endl;
}

int Phaser::getCurrentAmmos() const
{
    return this->_curAmmo;
}

Phaser::~Phaser()
{
    deleteAllBullets();
}

void Phaser::deleteAllBullets()
{
    MyAmmo *tmp = firstBullet;
    MyAmmo *del;
    while (tmp)
    {
        del = tmp;
        tmp = tmp->next;
        delete del;
        _curAmmo--;
    }
}

Phaser::MyAmmo::MyAmmo(Phaser::AmmoType type)
{
    this->type = type;
    this->next = nullptr;
}
