/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** general.cpp
*/

#include "ex04/TableRand.hpp"
#include "ex03/PapaXmasElf.hpp"

Object **MyUnitTests()
{
    Object ** array = new Object*[2];
    array[0] = new LittlePony("happy pony");
    array[1] = new Teddy("cuddles");
    return array;
}

Object *MyUnitTests(Object ** objs)
{
    int i = 0;
    Object *ret = nullptr;
    while (objs[i])
    {
        if (i > 2)
            std::cerr << "too long array" << std::endl;
        i++;
    }
    if (i < 3)
        std::cerr << "too small array" << std::endl;
    if (i == 3)
    {
        auto *teddy = dynamic_cast<Teddy *>(objs[0]);
        auto *box = dynamic_cast<Box *>(objs[1]);
        auto *giftpaper = dynamic_cast<GiftPaper *>(objs[2]);
        if (teddy->getType() != "Teddy")
            std::cerr << "first obj is no teddy: " << teddy->getType() << std::endl;
        if (box->getType() != "Box")
            std::cerr << "second obj is no box: " << box->getType() << std::endl;
        if (giftpaper->getType() != "GiftPaper")
            std::cerr << "third obj is no GiftPaper: " << giftpaper->getType()<< std::endl;
        if (!box ->getOpen())
            box->openMe();
        box->wrapMeThat(*teddy, false);
        box->closeMe();
        giftpaper->wrapMeThat(*box, false);
        giftpaper->closeMe();
        ret = giftpaper;
    }
    return ret;
}

std::ostream &operator<<(std::ostream &ostream, Object &obj)
{
    std::string type = obj.getType();
    if (type == "Wrap" || type == "Box" || type == "GiftPaper")
        ostream << dynamic_cast<Wrap&>(obj);
    else if (type == "Toy" || type == "Teddy" || type == "LittlePony")
        ostream << dynamic_cast<Toy&>(obj);
    return ostream;
}