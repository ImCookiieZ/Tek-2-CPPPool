/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07M_karl_erik_stoerzel
** File description:
** Federation.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_FEDERATION_HPP
#define B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_FEDERATION_HPP

#include "WarpSystem.hpp"
#include <iostream>
#include <string>
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        private:
            std::string _name;
            int _age = 0;
        public:
            explicit Captain(std::string name);
            std::string getName();
            int getAge();
            void setAge(int age);

        };
        class Ensign
        {
        private:
            std::string _name;
        public:
            explicit Ensign(std::string name);
        };
        class Ship
        {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            bool _inStarfleet = true;
            WarpSystem::Core *_core = nullptr;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield = 100;
            int _photonTorpedo = 0;

            void construct_base(int length, int width, const std::string &name, short maxWarp);
        public:
            Ship(int length, int width, std::string name, short maxWarp);
            Ship(int length, int width, std::string name, short maxWarp, bool federation);

            int getShield() const;
            void setShield(const int &shield);
            int getTorpedo() const;
            void setTorpedo(const int &torpedo);

            void setupCore(WarpSystem::Core *newCore);
            void checkCore();
            void promote(Captain *newCaptain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        };
    }
    class Ship : public Starfleet::Ship
    {
    public:
        Ship(int length, int width, std::string name);
    };
}

#endif //B_CPP_300_BER_3_1_CPPD07M_KARL_ERIK_STOERZEL_FEDERATION_HPP
