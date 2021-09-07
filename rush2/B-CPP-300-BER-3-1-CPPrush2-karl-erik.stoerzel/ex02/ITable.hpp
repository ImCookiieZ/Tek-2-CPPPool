/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ITABLE_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ITABLE_HPP

#include "../ex00/Object.hpp"

class ITable {
protected:
    bool _tableFunctional = true;
public:
    virtual void put(Object *obj) = 0;
    virtual Object *take(int index) = 0;
    virtual Object *take(Object *obj) = 0;
    virtual Object *takeFirst() = 0;
    virtual void collapse() = 0;
    virtual Object **look() = 0;
    virtual bool isTableFunctional() const = 0;
    virtual void setTableFunctional() = 0;
};
#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ITABLE_HPP
