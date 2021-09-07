/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Toy.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOY_HPP
#define B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOY_HPP

#include <iostream>
#include <string>
#include "Picture.hpp"

class Toy
{
public:
    enum ToyType
    {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };
protected:
    ToyType _type;
    std::string _name;
    Picture *_picture;
public:
    Toy();
    Toy(Toy const &from);
    Toy(ToyType type, std::string name, std::string filepath);
    ~Toy();

    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;

    void setName(std::string name);
    bool setAscii(std::string filepath);

//    Toy &operator=(Toy const &from);
};

#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOY_HPP
