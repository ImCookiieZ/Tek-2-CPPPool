/*
** EPITECH PROJECT, 2021
** morning
** File description:
** FriutBox.hpp
*/

#ifndef MORNING_FRIUTBOX_HPP
#define MORNING_FRIUTBOX_HPP

#include "FruitNode.hpp"

class FruitBox
{
protected:
    int _size;
    FruitNode *_head;
public:
    explicit FruitBox(int size);
    ~FruitBox();
    int nbFruits() const;
    bool putFruit(Fruit *fruit);
    Fruit *pickFruit();
    FruitNode *head() const;
};

#endif //MORNING_FRIUTBOX_HPP
