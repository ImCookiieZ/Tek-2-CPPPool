/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASCONVEYORBELT_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASCONVEYORBELT_HPP

#include "../ex01/Box.hpp"
#include "../ex01/GiftPaper.hpp"
#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt{
public:
    PapaXmasConveyorBelt();
    bool put(Object *obj) final;
    Object *take() final;
    void IN() override;
    void OUT() final;
    Object *getContent() const;

protected:
    Object *_content;
};
IConveyorBelt *createConveyorBelt();
#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_PAPAXMASCONVEYORBELT_HPP
