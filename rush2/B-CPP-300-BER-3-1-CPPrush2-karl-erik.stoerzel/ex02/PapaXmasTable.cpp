/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "PapaXmasTable.hpp"
#include "../ex00/LittlePony.hpp"
#include "../ex00/Teddy.hpp"
#include "../ex01/GiftPaper.hpp"
#include "../ex01/Box.hpp"

PapaXmasTable::PapaXmasTable()
{
    for (int i = 0; i < 11; i++)
        _objs[i] = nullptr;
    _objs[0] = new LittlePony("BOSS PONY");
    _objs[1] = new Teddy("TED");
    _objs[2] = new Box();
    _objs[3] = new Box();
    _objs[4] = new GiftPaper();
    _objs[5] = new GiftPaper();
}

PapaXmasTable::~PapaXmasTable()
{
    for (int i = 0; i < 11; i++)
        if (_objs[i])
            delete _objs[i];
}

Object *PapaXmasTable::takeFirst()
{
    Object *ret = nullptr;
    if (!_tableFunctional)
    {
        std::cerr << "Table is broke!" << std::endl;
        return nullptr;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (_objs[i])
            {
                ret = _objs[i];
                _objs[i] = nullptr;
            }
        }
    }
    if (!ret)
        std::cerr << "No objects on the Table" << std::endl;
    return ret;
}

Object *PapaXmasTable::take(int index)
{
    if (!_tableFunctional)
    {
        std::cerr << "Table is broke!" << std::endl;
        return nullptr;
    }
    Object *ret = nullptr;
    if (index >= 0 && index < 10)
    {
        ret = _objs[index];
        _objs[index] = nullptr;
    }
    else
        std::cerr << "index out of range" << std::endl;
    return ret;
}

Object *PapaXmasTable::take(Object *obj)
{
    if (!_tableFunctional)
    {
        std::cerr << "Table is broke!" << std::endl;
        return nullptr;
    }
    Object *ret = nullptr;
    if (!obj)
        std::cerr << "obj is nullptr" << std::endl;
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (_objs[i] == obj)
            {
                ret = _objs[i];
                _objs[i] = nullptr;
                return ret;
            }
        }
    }
    std::cerr << "obj is not on the table" << std::endl;
    return ret;
}

void PapaXmasTable::put(Object *obj)
{
    if (!_tableFunctional)
    {
        std::cerr << "Table is broke!" << std::endl;
        return;
    }
    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
        if (_objs[i] == obj)
        {
            std::cerr << "obj is already on the table" << std::endl;
            return;
        }
    }
    for (; _objs[idx]; idx++);
    if (idx == 10)
    {
        collapse();
        return;
    }
    _objs[idx] = obj;
}

void PapaXmasTable::collapse()
{
    for (int i = 0; i < 11; i++)
        _objs[i] = nullptr;
}

Object **PapaXmasTable::look()
{
    return _objs;
}

bool PapaXmasTable::isTableFunctional() const
{
    return _tableFunctional;
}

void PapaXmasTable::setTableFunctional()
{
    if (_tableFunctional)
        std::cerr << "Table is already functional!!" << std::endl;
    _tableFunctional = true;
}

ITable *createTable()
{
    return new PapaXmasTable();
}

std::ostream &operator<<(std::ostream &stream, PapaXmasTable &table)
{
    Object **objs = table.look();
    for (int i = 0; i < 11; i++)
        if (objs[i])
            stream << *objs[i];
    return stream;
}