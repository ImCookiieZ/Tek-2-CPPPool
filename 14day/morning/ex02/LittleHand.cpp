/*
** EPITECH PROJECT, 2021
** morning
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Fruit.hpp"
#include "Lime.hpp"

void LittleHand::sortFruitBox
    (FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    int nbFruits = unsorted.nbFruits();
    Fruit* fruit = unsorted.pickFruit();
    for (int i = 0; i < nbFruits && fruit; i++)
    {
        if (dynamic_cast<Lime*>(fruit) != nullptr)
        {
            if (!limes.putFruit(fruit))
                unsorted.putFruit(fruit);
        }
        else if (dynamic_cast<Lemon*>(fruit) != nullptr)
        {
            if (!lemons.putFruit(fruit))
                unsorted.putFruit(fruit);
        }
        else if (dynamic_cast<Banana*>(fruit) != nullptr)
        {
            if (!bananas.putFruit(fruit))
                unsorted.putFruit(fruit);
        }
        else
            unsorted.putFruit(fruit);
        if (i < nbFruits - 1)
            fruit = unsorted.pickFruit();
    }
}

FruitBox *const *LittleHand::organizeCoconut(const Coconut *const *coconuts)
{
    if (!coconuts)
        return nullptr;
    int nbCurBox = 0;
    int counterCoconut;
    for (counterCoconut = 0; coconuts[counterCoconut]; counterCoconut++);
    int nbBoxes = counterCoconut / 6 + (counterCoconut % 6 == 0 ? 0 : 1);
    auto **boxes = new FruitBox*[nbBoxes + 1];
    for (int i = 0; i < nbBoxes; i++)
        boxes [i] = new FruitBox(6);
    boxes[nbBoxes] = nullptr;
    for (int i = 0; i < counterCoconut; i++)
    {
        boxes[i]->putFruit((Fruit *) coconuts[i]);
        i++;
        if (i % 6 == 0)
            nbBoxes++;
    }
    return boxes;
}