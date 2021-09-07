/*
** EPITECH PROJECT, 2021
** morning
** File description:
** LittleHand.hpp
*/

#ifndef MORNING_LITTLEHAND_HPP
#define MORNING_LITTLEHAND_HPP

#include "FruitBox.hpp"
#include "Coconut.hpp"
#include "vector"
class LittleHand
{
public:
    static void sortFruitBox
    (FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox&limes);
    static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
};

#endif //MORNING_LITTLEHAND_HPP
