/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Object.cpp
*/

#include "../ex01/Wrap.hpp"
#include "Toy.hpp"
#include "Object.hpp"

Object::Object(std::string type)
{
    _type = type;
}

std::string Object::getType() const
{
    return _type;
}

void Object::isTaken() const
{

}

std::string Object::toXML() const
{
    Wrap *tmp = (Wrap *)this;
    Toy *tmptoy = (Toy *)this;
    if (this->getType() == "Teddy" ||
        this->getType() == "LittlePony") {
        return ("<Object>\n<Type>" + this->getType() +
        "</Type>\n<Name>" + tmptoy->getName() + "</Name>\n</Object>\n");
    }
    else if (tmp->getContent() == nullptr) {
        return ("<Object>\n<Type>" + this->getType() +
                "</Type>\n<Content></Content>\n</Object>\n");
    }
    else {
        return ("<Object>\n<Type>" + this->getType() +
        "</Type>\n<Content>\n" + tmp->getContent()->toXML() +
        "</Content>\n</Object>\n");
    }

}

void Object::toXMLFile(std::string name) const
{
    std::ofstream file(name + ".xml");
    file << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\" ?>\n"
    << this->toXML();
    file.close();
}

