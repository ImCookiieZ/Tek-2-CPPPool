/*
** EPITECH PROJECT, 2021
** morning
** File description:
** FruitNode.hpp
*/

#ifndef MORNING_FRUITNODE_HPP
#define MORNING_FRUITNODE_HPP

#include "Fruit.hpp"

typedef struct FruitNode_s{
    FruitNode_s *next;
    Fruit *_fruit;
} FruitNode;

#endif //MORNING_FRUITNODE_HPP
