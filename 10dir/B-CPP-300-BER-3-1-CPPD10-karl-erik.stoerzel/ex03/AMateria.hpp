/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** AMateria.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AMATERIA_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
public :
    explicit AMateria(const std :: string & type) ;
    virtual ~AMateria () = default;
    const std::string &getType() const; // Returns the materia type
    unsigned int getXP() const; // Returns the Materia 's XP
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
private :
    unsigned int xp_ ;
    std::string _type;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_AMATERIA_HPP
