/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASTABLE_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASTABLE_HPP

#include "ITable.hpp"

class PapaXmasTable : public ITable
{
protected:
    Object *_objs[11]{};
public:
    PapaXmasTable();
    ~PapaXmasTable();
    Object *take(int index) final ;
    Object *take(Object *obj) final ;
    Object *takeFirst() final ;
    void put(Object *obj) final ;
    void collapse() final ;
    Object **look() final ;
    bool isTableFunctional() const final ;
    void setTableFunctional() final ;
};

std::ostream &operator<<(std::ostream &stream, PapaXmasTable &table);
ITable *createTable();
#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASTABLE_HPP
