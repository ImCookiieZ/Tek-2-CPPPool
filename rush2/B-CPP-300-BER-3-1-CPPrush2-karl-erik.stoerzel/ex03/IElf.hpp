//
// Created by olaf_der_zertoerer on 16.01.21.
//

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_IELF_H
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_IELF_H

#include "../ex01/Wrap.hpp"
#include "../ex02/PapaXmasTable.hpp"
#include "../ex02/PapaXmasConveyorBelt.hpp"

class IElf
{
public:
    //ex01
    virtual Wrap *wrap(Wrap *wrapWith, Object *toWrap) const = 0;
    virtual Object *unWrap(Wrap *wrap) const = 0;
    virtual void openWrap(Wrap *wrap) const = 0;
    virtual void closeWrap(Wrap *wrap) const = 0;
    virtual void makeTableFunctional() const = 0;
    virtual void look() const = 0;
    //ex02
    virtual void fromTableToBelt(Object *obj) const = 0;
    virtual void fromBeltToTable() const = 0;
    virtual void pressInButton() const = 0;
    virtual void pressOutButton() const = 0;
    //setter and getter
    virtual void setTable(PapaXmasTable *table) = 0;
    virtual void setBelt(PapaXmasConveyorBelt *belt) = 0;
    virtual PapaXmasTable *getTable() const = 0;
    virtual PapaXmasConveyorBelt *getBelt() const = 0;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_IELF_H
