/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Lemon.hpp
*/

#ifndef MORNING_LEMON_HPP
#define MORNING_LEMON_HPP

#include "Fruit.hpp"

class Lemon : public Fruit
{
protected:
    Lemon(std::string name, int vitamins);
public:
    Lemon();
};

#endif //MORNING_LEMON_HPP
