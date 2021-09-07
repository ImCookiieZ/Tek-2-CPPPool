/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD10_karl_erik_stoerzel
** File description:
** Squad.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SQUAD_HPP
#define B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SQUAD_HPP

#include "ISquad.hpp"

//class SpaceMarineArray
//{
//public:
//    SpaceMarineArray *next;
//    ISpaceMarine *here;
//    explicit SpaceMarineArray(ISpaceMarine *newMarine);
//    ~SpaceMarineArray();
//    SpaceMarineArray(SpaceMarineArray const &copyFrom);
//    int push(ISpaceMarine *pushThis);
////    ISpaceMarine *getUnit(int pos);
//    ISpaceMarine *operator[](int pos) const;
//};

class Squad : public ISquad
{
private:
    int _nbUnits;
    ISpaceMarine *_units[201]{};
public:
    Squad();
    Squad(Squad &copyFrom);
    ~Squad() override;
    int getCount() const override;
    ISpaceMarine *getUnit(int nb) override;
    int push(ISpaceMarine *pushThis) override;
    Squad &operator=(Squad const &copy);
};

#endif //B_CPP_300_BER_3_1_CPPD10_KARL_ERIK_STOERZEL_SQUAD_HPP
