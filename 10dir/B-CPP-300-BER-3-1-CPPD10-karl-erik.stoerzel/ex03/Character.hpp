/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Character.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    AMateria *_mats[4]{};
    std::string _name;
public:
    explicit Character(std::string const &name);
    Character(Character const &copyFrom);
    ~Character() override;
    std::string const &getName() const override ;
    void equip(AMateria* m) override ;
    void unequip(int idx) override ;
    void use(int idx, ICharacter& target) override ;
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_CHARACTER_HPP
