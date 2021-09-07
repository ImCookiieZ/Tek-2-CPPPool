/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

std::string Fruit::getName() const
{
    return _name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}

Fruit::Fruit(std::string name, int vitamins)
{
    _name = name;
    _vitamins = vitamins;
}

Fruit::~Fruit()
{

}

