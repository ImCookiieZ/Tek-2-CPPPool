/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Character.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP

#include "AEnemy.hpp"
#include "AWeapon.hpp"

class Character
{
public :
    explicit Character(const std::string &name);
    ~Character() = default;
    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(AEnemy *enemy);
    std :: string virtual getName() const;
    int getAp() const;
    AWeapon *getWeapon() const;
private :
    std::string _name;
    int _ap;
    AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &stream, const Character &character);

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP
