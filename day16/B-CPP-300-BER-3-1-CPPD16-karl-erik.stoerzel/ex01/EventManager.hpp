/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** EventManager.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENTMANAGER_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENTMANAGER_HPP

#include "Event.hpp"
#include <list>
#include <iostream>

class EventManager
{
private:
    unsigned int _time;
    std::list<Event> _events;
public:
    EventManager();
    ~EventManager();
    EventManager(EventManager const &form);
    EventManager &operator=(EventManager const &from);

    void addEvent(const Event &event);
    void removeEventsAt(unsigned int time);
    void dumpEvents() const;
    void dumpEventAt(unsigned int time) const;
    void addTime(unsigned int time, bool change = true);
    void addEventList(const std::list<Event> &events);
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENTMANAGER_HPP
