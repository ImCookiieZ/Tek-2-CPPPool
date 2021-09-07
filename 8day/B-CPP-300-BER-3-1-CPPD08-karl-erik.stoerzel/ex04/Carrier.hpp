/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Carrier.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_CARRIER_HPP
#define B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_CARRIER_HPP

#include "Droid.hpp"

class Carrier
{
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    Droid** _droids;
public:
    explicit Carrier(std::string id = "");
    ~Carrier();
    //operator
    Carrier &operator<<(Droid *&addDroid);
    Carrier &operator>>(Droid *&removeDroid);
    Droid *&operator[](int position) const;
    Carrier &operator~();
    Carrier &operator<<(size_t &energy);
    bool operator()(int x, int y);

    //getter
    size_t getSpeed() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string getId() const;

    //setter
    void setId(const std::string &id);
    void setEnergy(const size_t &energy);

    size_t calcSpeed() const;

    size_t getPassengers() const;
};
std::ostream &operator<<(std::ostream &ostream, const Carrier &carrier);
#endif //B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_CARRIER_HPP
