/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AEnemy.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AENEMY_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AENEMY_HPP

#include <iostream>
#include <string>

class AEnemy
{
private :
    int _hp;
    std::string _type;
public :
    AEnemy(int hp, const std::string &type);
    virtual ~AEnemy();
    virtual void takeDamage(int damage);
    std :: string getType() const;
    int getHP() const ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AENEMY_HPP
