/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** MateriaSource.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MATERIASOURCE_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MATERIASOURCE_HPP


#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_mats[4]{};
public:
    MateriaSource();

    AMateria * createMateria(std::string const & type) override ;
    void learnMateria(AMateria* m) override ;

};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_MATERIASOURCE_HPP
