/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt() : _content(nullptr)
{
}

IConveyorBelt *createConveyorBelt()
{
    return (new PapaXmasConveyorBelt());
}

bool PapaXmasConveyorBelt::put(Object *obj) {
    if (this->_content == nullptr)
    {
        this->_content = obj;
        return true;
    }
    else
        std::cerr << "The conveyor belt is occupied" << std::endl;
    return false;
}

Object *PapaXmasConveyorBelt::take()
{
    if (this->_content != nullptr) {
        Object *tmp = this->_content;
        this->_content = nullptr;
        return (tmp);
    } else
        std::cerr << "There is nothing on the conveyor belt" << std::endl;
    return (nullptr);
}

void PapaXmasConveyorBelt::IN()
{
    static int n = 0;
    if (this->_content == nullptr) {
        if (n % 2 == 0)
            this->_content = new Box();
        else
            this->_content = new GiftPaper();
        return;
    } else
        std::cerr << "The conveyor belt is occupied" << std::endl;
    n += 1;
}

void PapaXmasConveyorBelt::OUT()
{
    static int i = 0;
    if (this->_content && this->_content->getType() == "GiftPaper") {
        Wrap *tmp = dynamic_cast<Wrap *>(this->_content);
        while (tmp->getContent())
        {
            if (tmp->getContent()->getType() != "Teddy" &&
                tmp->getContent()->getType() != "LittlePony")
            {
                tmp = dynamic_cast<Wrap *>(tmp->getContent());
            }
            else
            {
                i++;
                this->_content->toXMLFile(std::to_string(i));
                delete this->_content;
                this->_content = nullptr;
                return;
            }
        }
        std::cerr << "The object has no toy inside" << std::endl;
    } else if (!this->_content)
        std::cerr << "The conveyor belt is empty" << std::endl;
    else
        std::cerr << "The object needs gift paper" << std::endl;

}

Object *PapaXmasConveyorBelt::getContent() const {
    return this->_content;
}
