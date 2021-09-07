/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** Character.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_CHARACTER_HPP
#define B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_CHARACTER_HPP

#include <iostream>
#include <string>

class Character
{
protected:
    int _pv = 100;
    int _power = 100;

    int _stamina = 5;
    int _spirit = 5;
    int _agility = 5;

    int _strength = 5;
    int _intelligence = 5;
    void notEnoughEnergy();

    std::string _name = "";
    int _level = 1;
//    Character();
public:
    Character(std::string name, size_t level);
    enum AttackRange
    {
        CLOSE,
        RANGE
    };
    AttackRange Range = CLOSE;

    const std::string &getName();
    int getLvl() const;
    int getPv() const;
    int getPower() const;

    virtual int CloseAttack();
    virtual int RangeAttack();
    virtual void Heal();
    virtual void RestorePower();
    void TakeDamage(int damage);
};

#endif //B_CPP_300_BER_3_1_CPPD09_KARL_ERIK_STOERZEL_CHARACTER_HPP
