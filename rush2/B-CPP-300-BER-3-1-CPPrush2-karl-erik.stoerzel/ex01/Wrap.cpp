/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string type) : Object(type)
{
    _content = nullptr;
    _isOpen = true;
}

void Wrap::wrapTalk()
{
    std::cout << "tuuuut tuuut tuut" << std::endl;
}

void Wrap::isTaken() const
{
    std::cout << "whistles while working" << std::endl;
}

Object *Wrap::TakeContent(bool santa)
{
    Object *ret = nullptr;
    if (_isOpen)
    {
        if (isWrapped())
        {
            if (!santa)
                _content->isTaken();
            ret = _content;
            _content = nullptr;
        }
        else
            std::cerr << "No content" << std::endl;
    }
    else
        std::cerr << "Wrap is not open" << std::endl;
    return ret;
}

void Wrap::setContent(Object *content)
{
    _content = content;
}

bool Wrap::isWrapped() const
{
    return _content;
}

void Wrap::wrapMeThat(Object &objToWrap, bool santa)
{
    if (!santa)
    {
        objToWrap.isTaken();
        wrapTalk();
    }
    _content = &objToWrap;
}

void Wrap::closeMe()
{
    if (!_isOpen)
        std::cerr << "wrap is already closed..." << std::endl;
    _isOpen = false;
}

void Wrap::openMe()
{
    if (_isOpen)
        std::cerr << "wrap is already open..." << std::endl;
    _isOpen = true;
}

Object *Wrap::getContent() const {
    return this->_content;
}

Wrap::~Wrap()
{
    delete _content;
}

bool Wrap::getOpen() const
{
    return _isOpen;
}

std::ostream &operator<<(std::ostream &ostream, Wrap const &wrap)
{
    std::string open = wrap.getOpen() ? "open" : "close";
    if (wrap.getContent() != nullptr)
    {
        ostream << wrap.getType() << " is " << open << " and contains: a " << wrap.getContent()
        ->getType()<<
        std::endl;
        ostream << *wrap.getContent();
    }
    else
        ostream << wrap.getType() << " is " << open << " and contains nothing" << std::endl;
    return ostream;
}