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
    class Error
    {
    private:
    public:
        enum ErrorType
        {
            UNKNOWN, PICTURE, SPEAK
        };
        ErrorType type;
        std::string what() const;
        std::string where() const;
    };
protected:
    Error _error;
private:
    ToyType _type;
    std::string _name;
    Picture *_picture;
    bool _sp = false;
public:
    Toy();
    Toy(ToyType type, std::string name, std::string filepath);
    Toy(Toy const &from);
//    virtual ~Toy();
    void setSp(bool sp);
    bool getSp() const;
    ToyType getType() const;
    std::string getName() const;
    void setName(std::string name);
    bool setAscii(std::string filepath);
    std::string getAscii() const;
    Toy::Error getLastError() const;

    virtual bool speak(std::string statement);
    virtual bool speak_es(std::string statement);

    Toy &operator=(Toy const &from);
    Toy &operator<<(std::string picture);
};
std::ostream &operator<<(std::ostream &stream, Toy::ToyType type);
std::ostream &operator<<(std::ostream &stream, Toy toy);
#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_TOY_HPP
