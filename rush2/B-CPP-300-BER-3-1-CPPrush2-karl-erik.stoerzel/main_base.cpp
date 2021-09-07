/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** main_base.cpp
*/

#include "ex04/TableRand.hpp"
#include "ex03/PapaXmasElf.hpp"

Object **MyUnitTests();
Object *MyUnitTests(Object ** objs);

int main()
{
    auto *ted = new Teddy("Ted");
    auto *pony = new LittlePony("Pink Fluffy Unicorn");
    auto *box = new Box();
    auto *box2 = new Box();
    auto *paper = new GiftPaper();
    auto *paper2 = new GiftPaper();

    Object **obs = new Object*[4];
    obs[0] = ted;
    obs[1] = box;
    obs[2] = paper;

     obs[3] = nullptr;
    Object *ret = MyUnitTests(obs);
    paper->toXMLFile("emptyPaper");
    box->toXMLFile("justABox");
    ted->toXMLFile("justAToy");
    paper->wrapMeThat(*box, false);
    paper->toXMLFile("noToy");
    box->wrapMeThat(*ted, false);
    paper->toXMLFile("tedPresent");
    paper2->wrapMeThat(*box2, false);
    box2->wrapMeThat(*pony, false);
    paper2->toXMLFile("ponyPresent");

    auto table = new TableRand();
    auto belt = new ConveyorBeltRand();
    auto elf = new PapaXmasElf(table, belt);
    elf->look();

    std::cout << std::endl;
    TableRand table_ = TableRand();
    std::cout << table_;
    table_.TableRand::wrapPresents();
    return (0);
}