/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Lemon.cpp
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3)
{}

Lemon::Lemon(std::string name, int vitamins) : Fruit(name, vitamins)
{
}