/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD08_karl_erik_stoerzel
** File description:
** DroidMemory.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROIDMEMORY_HPP
#define B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROIDMEMORY_HPP

#include <iostream>
#include <string>

class DroidMemory
{
private:
    size_t _fingerprint;
    size_t _exp;
public:
    //constructor
    DroidMemory();
    DroidMemory(const DroidMemory &copyFrom);
    //methods
    void addExp(const size_t &exp);
    //gets
    size_t getFingerprint() const;
    size_t getExp() const;
    //sets
    void setFingerprint(const size_t &newFingerprint);
    void setExp(const size_t &newExp);

    //operators
    DroidMemory &operator<<(const DroidMemory &addMemory);
    DroidMemory &operator>>(DroidMemory &addMemory) const;

    DroidMemory &operator+=(const DroidMemory &right);
    DroidMemory &operator+=(const size_t &right);
    DroidMemory &operator+(const DroidMemory &right);
    DroidMemory &operator+(const size_t &right);
    bool operator==(const DroidMemory &other) const;
    bool operator!=(const DroidMemory &other) const;
    bool operator>(const DroidMemory &other) const;
    bool operator<(const DroidMemory &other) const;
    bool operator<=(const DroidMemory &other) const;
    bool operator>=(const DroidMemory &other) const;
    bool operator==(const size_t &other) const;
    bool operator!=(const size_t &other) const;
    bool operator>(const size_t &other) const;
    bool operator<(const size_t &other) const;
    bool operator<=(const size_t &other) const;
    bool operator>=(const size_t &other) const;
};
std::ostream &operator<<(std::ostream &stream, const DroidMemory &memory);
#endif //B_CPP_300_BER_3_1_CPPD08_KARL_ERIK_STOERZEL_DROIDMEMORY_HPP
