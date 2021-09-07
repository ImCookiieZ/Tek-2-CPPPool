/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ICONVEYORBELT_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ICONVEYORBELT_HPP

#include "../ex01/Wrap.hpp"

class IConveyorBelt {
public:
    virtual bool put(Object *obj) = 0;
    virtual Object *take() = 0;
    virtual void IN() = 0;
    virtual void OUT() = 0;
};

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_ICONVEYORBELT_HPP
