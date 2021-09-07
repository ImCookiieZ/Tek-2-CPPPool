/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Event.cpp
*/

#include "Event.hpp"

Event::Event()
{
    _time = 0;
}

Event::Event(unsigned int time, const std::string &event)
{
    _time = time;
    _event = event;
}

Event::Event(const Event &from)
{
    _time = from._time;
    _event = from._event;
}

Event &Event::operator=(const Event &from)
{
    _time = from._time;
    _event = from._event;
    return *this;
}

unsigned int Event::getTime() const
{
    return _time;
}

const std::string &Event::getEvent() const
{
    return _event;
}

void Event::setTime(unsigned int time)
{
    _time = time;
}

void Event::setEvent(const std::string &event)
{
    _event = event;
}
