/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** PapaXmasElf.cpp
*/

#include "PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf(PapaXmasTable *table, PapaXmasConveyorBelt *belt)
{
    _table = table;
    _belt = belt;
}

Wrap *PapaXmasElf::wrap(Wrap *wrapWith, Object *toWrap) const
{
    if (!wrapWith)
    {
        std::cerr << "nothing to wrap with..." << std::endl;
        return nullptr;
    }
    if (!toWrap)
    {
        std::cerr << "nothing to wrap..." << std::endl;
        return nullptr;
    }
    if (!wrapWith->getOpen())
        wrapWith->openMe();
    wrapWith->wrapMeThat(*toWrap, false);
    wrapWith->closeMe();
    return wrapWith;
}

Object *PapaXmasElf::unWrap(Wrap *wrap) const
{
    Object *ret = nullptr;
    if (!wrap)
    {
        std::cerr << "nothing to unwrap..." << std::endl;
        return ret;
    }
    if (!wrap->getOpen())
        wrap->openMe();
    ret = wrap->TakeContent(false);
    return ret;
}

void PapaXmasElf::openWrap(Wrap *wrap) const
{
    if (!wrap)
    {
        std::cerr << "nothing to open..." << std::endl;
    }
    wrap->openMe();
}

void PapaXmasElf::closeWrap(Wrap *wrap) const
{
    if (!wrap)
    {
        std::cerr << "nothing to open..." << std::endl;
    }
    wrap->closeMe();
}

void PapaXmasElf::makeTableFunctional() const
{
    if (!_table)
    {
        std::cerr << "I need a table please!" << std::endl;
    }
    else
    {
        _table->setTableFunctional();
    }
}

void PapaXmasElf::look() const
{
    if (!_table)
    {
        std::cerr << "I need a table please!" << std::endl;
    }
    else
    {
        std::cout << "On my table is:" << std::endl;
        std::cout << *_table;
    }
}

PapaXmasTable *PapaXmasElf::getTable() const
{
    return _table;
}

PapaXmasConveyorBelt *PapaXmasElf::getBelt() const
{
    return _belt;
}

void PapaXmasElf::setTable(PapaXmasTable *table)
{
    _table = table;
}

void PapaXmasElf::setBelt(PapaXmasConveyorBelt *belt)
{
    _belt = belt;
}

void PapaXmasElf::fromTableToBelt(Object *obj) const
{
    if (!_table)
    {
        std::cerr << "I need a table please!" << std::endl;
    }
    if (!_belt)
    {
        std::cerr << "I need a belt please!" << std::endl;
    }
    if (!obj)
        std::cerr << "Nothing to do without an object :)" << std::endl;
    if (_table && _belt && obj)
    {
        Object *tmp = _table->take(obj);
        if (!tmp)
        {
            std::cerr << "Object is not on the table" << std::endl;
            return;
        }
        if (!_belt->put(obj))
            _table->put(obj);
    }
}

void PapaXmasElf::fromBeltToTable() const
{
    if (!_table)
    {
        std::cerr << "I need a table please!" << std::endl;
    }
    if (!_belt)
    {
        std::cerr << "I need a belt please!" << std::endl;
    }
    if (_table && _belt)
    {
        Object *tmp = _belt->take();
        if (tmp)
            _table->put(tmp);
    }
}

void PapaXmasElf::pressInButton() const
{
    if (!_belt)
    {
        std::cerr << "I need a belt please!" << std::endl;
    }
    else
        _belt->IN();
}

void PapaXmasElf::pressOutButton() const
{
    if (!_belt)
    {
        std::cerr << "I need a belt please!" << std::endl;
    }
    else
        _belt->OUT();
}
