/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TABLERAND_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TABLERAND_HPP

#include "../ex02/PapaXmasTable.hpp"
#include "../ex01/Box.hpp"
#include "../ex01/GiftPaper.hpp"
#include "../ex00/Teddy.hpp"
#include "../ex00/LittlePony.hpp"
#include "../ex04/ConveyorBeltRand.hpp"


class TableRand : public PapaXmasTable
{
public:
    TableRand();
    void wrapPresents();
    Object *take_type(std::string type);
    Object *is_type(std::string type);

    void countObjects(int &paper, int &box, int &toys) const;

    void putObjects(ConveyorBeltRand *belt, int &paper, int &box, int &toys);

    Object *takeObject();

    void takeBox(Object *wraping, int &box, Object *&obj);

    void takeGiftPaper(Object *obj, ConveyorBeltRand *belt, int &paper, Object *&wraping);
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_TABLERAND_HPP
