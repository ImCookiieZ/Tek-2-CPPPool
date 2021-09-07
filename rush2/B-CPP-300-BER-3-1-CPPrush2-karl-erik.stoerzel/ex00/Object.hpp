/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Object.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_OBJECT_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_OBJECT_HPP

#include <iostream>
#include <fstream>
#include <string>

class Object
{
protected:
    std::string _type;
public:
    explicit Object(std::string type = "Object");
    std::string getType() const;
    virtual void isTaken() const;
    virtual ~Object() = default;

    std::string toXML() const;
    void toXMLFile(std::string name) const;
};

std::ostream &operator<<(std::ostream &ostream, Object &obj);

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_OBJECT_HPP
