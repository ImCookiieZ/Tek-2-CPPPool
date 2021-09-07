/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand() = default;

void ConveyorBeltRand::IN()
{
    if (this->_content == nullptr) {
        int n = (int)(random() % 2);
        if (n == 0)
            this->_content = new Box();
        else
            this->_content = new GiftPaper();
    }
    else
       std::cerr << "The conveyor belt is occupied" << std::endl;
}

void ConveyorBeltRand::serialize()
{
    std::cout << this->_content->toXML();
}
