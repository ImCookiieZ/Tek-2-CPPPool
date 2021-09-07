/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Phaser.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PHASER_HPP
#define B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PHASER_HPP

#include <iostream>
#include <string>
#include <map>
#include "Sounds.hpp"

class Phaser
{
public :
    enum AmmoType
    {
        REGULAR,
        PLASMA,
        ROCKET
    };
    Phaser (int maxAmmo = 20, AmmoType type = REGULAR);
    ~Phaser();
    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const;
private :
    class MyAmmo
    {
    public:
        MyAmmo(AmmoType type);
        AmmoType type;
        MyAmmo *next;
    };
    static const int Empty = 0;
    int _maxAmmo;
    int _curAmmo;
    AmmoType _defaultType;
    MyAmmo *firstBullet;
    MyAmmo *lastBullet;

    void deleteAllBullets();
};

#endif //B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PHASER_HPP
