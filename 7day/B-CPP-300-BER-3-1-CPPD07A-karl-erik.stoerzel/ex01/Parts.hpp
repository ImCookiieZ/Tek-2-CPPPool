/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** Parts.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PARTS_HPP
#define B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PARTS_HPP

#include <string>
#include <iostream>

class Parts
{
private:
    std::string _serial;
    bool _functional = true;
    std::string _type;
public:
    Parts(std::string serial, bool functional);

    std::string getType() const;
    void setType(std::string type);

    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};
class Arms : public Parts
{
    std::string _serial = "A-01";
public:
    explicit Arms(std::string serial = "A-01", bool functional = true);
};
class Legs : public Parts
{
    std::string  _serial = "L-01";
public:
    explicit Legs(std::string serial = "L-01", bool functional = true);
};
class Head : public Parts
{
    std::string _serial = "H-01";
public:
    explicit Head(std::string serial = "H-01", bool functional = true);
};

#endif //B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_PARTS_HPP
