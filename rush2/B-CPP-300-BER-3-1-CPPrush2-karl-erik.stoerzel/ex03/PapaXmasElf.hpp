//
// Created by olaf_der_zertoerer on 16.01.21.
//

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASELF_H
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASELF_H

#include "IElf.hpp"
#include "../ex02/PapaXmasTable.hpp"
#include "../ex02/PapaXmasConveyorBelt.hpp"

class PapaXmasElf : IElf
{
private:
    PapaXmasTable *_table;
    PapaXmasConveyorBelt *_belt;
public:
    PapaXmasElf(PapaXmasTable *table, PapaXmasConveyorBelt *belt);

    Wrap *wrap(Wrap *wrapWith, Object *toWrap) const final ;
    Object *unWrap(Wrap *wrap) const final ;
    void openWrap(Wrap *wrap) const final ;
    void closeWrap(Wrap *wrap) const final ;
    void makeTableFunctional() const final ;
    void look() const final ;
    //ex02
    void fromTableToBelt(Object *obj) const final ;
    void fromBeltToTable() const final ;
    void pressInButton() const final ;
    void pressOutButton() const final ;
    void setTable(PapaXmasTable *table) final ;
    void setBelt(PapaXmasConveyorBelt *belt) final ;
    PapaXmasTable *getTable() const final ;
    PapaXmasConveyorBelt *getBelt() const final ;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASELF_H
