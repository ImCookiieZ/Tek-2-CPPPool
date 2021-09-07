/*
** EPITECH PROJECT, 2021
** morning
** File description:
** FriutBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _size = size;
    _head = nullptr;
}

int FruitBox::nbFruits()
{
    FruitNode *tmp = _head;
    int i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

bool FruitBox::putFruit(Fruit *fruit)
{
    if (!fruit || nbFruits() == _size)
        return false;
    FruitNode *tmp = _head;
    if (!tmp)
    {
        _head = new FruitNode;
        _head->_fruit = fruit;
        _head->next = nullptr;
        return true;
    }
    while (tmp->next)
    {
        if (fruit == tmp->_fruit)
            return false;
        tmp = tmp->next;
    }
    if (fruit == tmp->_fruit)
        return false;
    tmp->next = new FruitNode;
    tmp->next->_fruit = fruit;
    tmp->next->next = nullptr;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    Fruit *tmpFruit;
    FruitNode *tmp = _head;
    if (tmp)
        _head = tmp->next;
    else
        return nullptr;
    tmpFruit = tmp->_fruit;
    delete tmp;
    return tmpFruit;
}

FruitNode *FruitBox::head()
{
    return _head;
}

FruitBox::~FruitBox()
{
    delete _head;
}