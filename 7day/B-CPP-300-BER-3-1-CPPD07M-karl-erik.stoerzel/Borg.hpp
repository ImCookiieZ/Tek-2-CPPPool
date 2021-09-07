/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** Borg.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_BORG_HPP
#define B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_BORG_HPP

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship
    {
    private:
        int _side;
        short  _maxWarp;
        WarpSystem::Core *_core = nullptr;
        Destination _location;
        Destination _home;
    public:
        Ship();
        void setupCore(WarpSystem:: Core *core);
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    };
}

#endif //B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_BORG_HPP
