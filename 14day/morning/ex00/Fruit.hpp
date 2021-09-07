/*
** EPITECH PROJECT, 2021
** morning
** File description:
** Fruit.hpp
*/

#ifndef MORNING_FRUIT_HPP
#define MORNING_FRUIT_HPP

#include <iostream>
#include <string>

class Fruit
{
protected:
    std::string _name;
    int _vitamins;
public:
    Fruit(std::string name, int vitamins);
    //Getter/Setter
    virtual std::string getName() const;
    int getVitamins() const;
};

#endif //MORNING_FRUIT_HPP
