/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "TableRand.hpp"

std::string random_name() {
    std::string Names[6] = {"arnold", "bob", "Chantal", "dilen", "emile", "kevin"};
    int randomName = (int)(random() % 6);
    return Names[randomName];
}

TableRand::TableRand()
{
    srand(time(NULL));
    int rand = 0;
    for (int i = 0; i < 10; i++)
    {
        rand = (int)(random() % 3);
        //wrap Chance = 1/3
        if (rand == 0)
        {
            rand = (int)(random() % 4);
            if (rand == 0)
                _objs[i] = new Box();
            else
                _objs[i] = new GiftPaper();
        }
        else
        {
            rand = (int)(random() % 2);
            if (rand == 0)
                _objs[i] = new Teddy(random_name());
            else
                _objs[i] = new LittlePony(random_name());
        }
    }
}

Object *TableRand::take_type(std::string type)
{
    Object *ret = nullptr;

    for (int i = 0; i < 10; i++)
    {
        if (_objs[i]) {
            if (_objs[i]->getType() == type) {
                ret = _objs[i];
                _objs[i] = nullptr;
                return ret;
            }
        }
    }
    return ret;
}

Object *TableRand::is_type(std::string type)
{
    Object *ret = nullptr;

    for (int i = 0; i < 10; i++)
    {
        if (_objs[i]) {
            if (_objs[i]->getType() == type) {
                ret = _objs[i];
                return ret;
            }
        }
    }
    return ret;
}

void TableRand::wrapPresents()
{
    int paper = 0;
    int box = 0;
    int toys = 0;
    Object *obj;
    Object *wraping;
    auto *belt = new ConveyorBeltRand;

    countObjects(paper, box, toys);
    while (is_type("Teddy") || is_type("LittlePony")) {
        if (paper == 0)
            return;
        obj = takeObject();
        putObjects(belt, paper, box, toys);
        toys--;
        takeBox(wraping, box, obj);
        takeGiftPaper(obj, belt, paper, wraping);
    }
}

void
TableRand::takeGiftPaper(Object *obj, ConveyorBeltRand *belt, int &paper, Object *&wraping)
{
    if ((wraping = take_type("GiftPaper"))) {
        paper--;
        dynamic_cast<Wrap*>(wraping)->wrapMeThat(*obj, false);
        belt->put(wraping);
        belt->OUT();
    }
}

void TableRand::takeBox(Object *wraping, int &box, Object *&obj)
{
    if ((wraping = take_type("Box"))) {
        box--;
        dynamic_cast<Wrap*>(wraping)->wrapMeThat(*obj, false);
        obj = wraping;
    }
}

Object *TableRand::takeObject()
{
    Object *obj;
    if (is_type("Teddy")) {
        obj = take_type("Teddy");
    } else
        obj = take_type("LittlePony");
    return obj;
}

void TableRand::putObjects(ConveyorBeltRand *belt, int &paper, int &box, int &toys)
{
    for (int i = toys + box + paper; i < 10; i++) {
        belt->IN();
        if ((belt->getContent())->getType() == "Teddy" || (belt->getContent())->getType() == "LittlePony")
            toys++;
        if ((belt->getContent())->getType() == "Box")
            box++;
        if ((belt->getContent())->getType() == "GiftPaper")
            paper++;
        put(belt->take());
    }
}

void TableRand::countObjects(int &paper, int &box, int &toys) const
{
    for (int i = 0; i < 10; i++) {
        if (_objs[i]->getType() == "Teddy" || _objs[i]->getType() == "LittlePony")
            toys++;
        if (_objs[i]->getType() == "Box")
            box++;
        if (_objs[i]->getType() == "GiftPaper")
            paper++;
    }
}
