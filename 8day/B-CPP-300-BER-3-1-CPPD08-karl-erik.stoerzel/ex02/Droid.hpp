/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** Droid.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROID_HPP
#define B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROID_HPP

#include <iostream>
#include <string>
#include "DroidMemory.hpp"
class Droid
{
private:
    std::string _id = "";
    size_t _energy = 50;
    const size_t Attack = 25;
    const size_t Toughness = 15;
    std::string *_status = new std::string ("Standing by");
    DroidMemory *_battleData = nullptr;
public:
    //constructors
    explicit Droid(const std::string& id);
    Droid(const Droid &copyFrom);
    //destructor
    ~Droid();

    //getter
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    DroidMemory *getBattleData() const;

    //setter
    void setId(const std::string& id);
    void setEnergy(const size_t &energy);
    void setStatus(const std::string *status);
    void setBattleData(const DroidMemory *setTo);
    //methods
    void talk(const std::string& sentence) const;
//    void operator(const std::string *task, const size_t exp);

    //opperators
    Droid &operator=(const Droid &assignWith);
    bool operator==(const Droid &compareWith) const;
    bool operator!=(const Droid &compareWith) const;
    size_t &operator<<(size_t &value);
    Droid &operator<<(Droid &value);
    bool operator()(const std::string *task, size_t exp);
};
std::ostream &operator<<(std::ostream &stream, const Droid &thisDroid);

#endif //B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROID_HPP
