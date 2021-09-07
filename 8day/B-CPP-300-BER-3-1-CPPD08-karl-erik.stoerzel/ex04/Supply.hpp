/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Supply.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_SUPPLY_HPP
#define B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_SUPPLY_HPP

#include "Carrier.hpp"

class Supply
{
public:
    enum Types
    {
        Iron = 1,
        Silicon = 2,
        Wreck = 3
    };
private:
    Types _type;
    size_t _amount;
    Droid **_wrecks;
    size_t _curWreck = 0;
public:
    Supply(Types type, size_t amount);
    Supply(Types type, size_t amount, Droid **&wrack);
    ~Supply();
    operator size_t() const;
    Droid * &operator *();
    Droid * operator ->() const;
    Supply &operator ! ();
    bool operator ==(Types type) const;
    bool operator !=(Types type) const;
    std::string getType() const ;
    Supply &operator++();
    Supply &operator--();
    void giveInformation(std::ostream &stream) const;
};
std::ostream &operator<<(std::ostream &stream, Supply &sub);
//size_t &operator=(coconst Supply &from);
//size_t operator=(size_t &ret, const Supply &from);
#endif //B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_SUPPLY_HPP
