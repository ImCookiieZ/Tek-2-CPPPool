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
private:
    ToyType _type;
    std::string _name;
    Picture *_picture;
public:
    Toy();
    Toy(ToyType type, std::string name, std::string filepath);
    Toy(Toy const &from);
//    virtual ~Toy();
    ToyType getType() const;
    std::string getName() const;
    void setName(std::string name);
    bool setAscii(std::string filepath);
    std::string getAscii() const;
    virtual bool speak(std::string statement);
    Toy &operator<<(std::string picture);

    Toy &operator=(Toy const &from);
};
std::ostream &operator<<(std::ostream &stream, Toy::ToyType type);
std::ostream &operator<<(std::ostream &stream, Toy toy);
#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOY_HPP
