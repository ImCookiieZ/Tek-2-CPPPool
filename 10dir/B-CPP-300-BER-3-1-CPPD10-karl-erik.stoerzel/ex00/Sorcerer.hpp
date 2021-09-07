/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Sorcerer.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SORCERER_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SORCERER_HPP

#include "Peon.hpp"

class Sorcerer
{
private:
    std::string _name;
    std::string _title;
    void talk(std::string sentence) const;
public:
    Sorcerer(std::string name, std::string title);
    ~Sorcerer();
    std::string getName() const;
    std::string getTitle() const;
    void polymorph(const Victim &victim) const;
};
std::ostream &operator<<(std::ostream &stream, const Sorcerer &sorcerer);

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SORCERER_HPP
