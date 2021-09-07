/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** EventManager.cpp
*/

#include "EventManager.hpp"

bool smaller(Event const &e1, Event const &e2)
{
    return e1.getTime() < e2.getTime();
}

EventManager::EventManager()
{
    _time = 0;
}

EventManager::~EventManager()
{
    _events.clear();
}

EventManager::EventManager(const EventManager &from)
{
    _events = from._events;
    _time = from._time;
    _events.sort(smaller);
}

EventManager &EventManager::operator=(const EventManager &from)
{
    _events = from._events;
    _time = from._time;
    _events.sort(smaller);
    return *this;
}

void EventManager::addEvent(const Event &event)
{
    _events.push_back(event);
    _events.sort(smaller);
}

void EventManager::removeEventsAt(unsigned int time)
{
    auto it = _events.begin();
    auto end = _events.end();
    while (it != end)
    {
        if (it->getTime() == time)
        {
            _events.erase(it);
            removeEventsAt(time);
            break;
        }
        it++;
    }
    _events.sort(smaller);
}

void EventManager::dumpEvents() const
{
    unsigned int it_time = 0;
    for (const Event& ev : _events)
    {
        it_time = ev.getTime();
        if (it_time > _time)
            std::cout << it_time << ": " << ev.getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    unsigned int it_time = 0;
    for (const Event& ev : _events)
    {
        it_time = ev.getTime();
        if (it_time == time)
            std::cout << it_time << ": " << ev.getEvent() << std::endl;
    }
}

void EventManager::addTime(unsigned int time, bool change)
{
    unsigned int it_time = 0;
    auto it = _events.begin();
    auto end = _events.end();
    while (it != end)
    {
        it_time = it->getTime();
        if (it_time > _time && it_time <= _time + time)
        {
            std::cout << it->getEvent() << std::endl;
            _events.erase(it);
            addTime(time, false);
            break;
        }
        it++;
    }
    _events.sort(smaller);
    if (change)
        _time += time;
}

void EventManager::addEventList(const std::list<Event> &events)
{
    auto it = events.begin();
    auto end = events.end();
    while (it != end)
    {
        if (it->getTime() > _time)
            _events.push_back(*it);
        it++;
    }
    _events.sort(smaller);
}