/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Event.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENT_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENT_HPP

#include <string>

class Event
{
private:
    unsigned int _time;
    std::string _event;
public:
    Event();
    Event(unsigned int time, const std::string &event);
    ~Event() = default;
    Event(const Event &from);
    Event &operator=(const Event &from);

    unsigned int getTime() const;
    const std::string &getEvent() const;
    void setTime(unsigned int time);
    void setEvent(const std::string &event);
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_EVENT_HPP
