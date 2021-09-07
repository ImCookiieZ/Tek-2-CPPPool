/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Victim.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_VICTIM_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
protected:
    std::string _name;
public:
    explicit Victim(std::string name);
    ~Victim();

    virtual void getPolymorphed() const;
    std::string getName() const;

};
std::ostream &operator<<(std::ostream &stream, const Victim &victim);

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_VICTIM_HPP
