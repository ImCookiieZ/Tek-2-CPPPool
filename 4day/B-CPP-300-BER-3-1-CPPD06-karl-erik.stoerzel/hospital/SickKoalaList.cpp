/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** SickKoalaList.cpp
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *start)
{
    this->koala = start;
    this->next = nullptr;
    this->head = this;
}

bool SickKoalaList::isEnd()
{
    return this->next == nullptr;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this->head;
    if (!tmp)
        return nullptr;
    while (tmp->next && (!tmp->koala || tmp->koala->getName() != name))
        tmp = tmp->next;
    if (tmp->next)
        return tmp->getContent();
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    SickKoalaList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (tmp == node)
    {
        this->setHeadToNext();
        return this->next;
    }
    else
    {
        while (tmp->next && tmp->next != node)
        {
            tmp = tmp->next;
            std::cout << "search\n";
        }
        if (tmp->next)
        {
            std::cout << "\n\nlol\n\n";
            tmp->next = tmp->next->next;
        }
    }
    return this->head;
}

void SickKoalaList::append(SickKoalaList *node)
{
    if (this->existsElement(node))
        return;
    SickKoalaList *tmp = this;
    while (tmp->next)
        tmp = tmp->next;
    if (!this->head)
        this->head = node;
    else
        tmp->next = node;
    node->head = this->head;
    node->next = nullptr;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (this->koala && this->koala->getName() == name)
    {
        this->setHeadToNext();
    }
    else
    {
        while (tmp->next)
        {
            if (tmp->next->koala && tmp->next->koala->getName() == name)
                break;
            tmp = tmp->next;
        }
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return this->head;
}

SickKoala *SickKoalaList::getContent()
{
    return this->koala;
}

SickKoalaList *SickKoalaList::getNext()
{
    return this->next;
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp = this->head;
    std::cout << "Patients: ";
    while (tmp && tmp->next)
    {
        std::cout << tmp->getContentName() << ", ";
        tmp = tmp->next;
    }
    if (tmp)
        std::cout << tmp->getContentName() << ".";
    std::cout << std::endl;
}

void SickKoalaList::setHeadToNext()
{
    SickKoalaList *tmp = this->head;
    if (!tmp)
        return;
    SickKoalaList *new_head = tmp->next;
    while (tmp->next)
    {
        tmp->head = new_head;
        tmp = tmp->next;
    }
    tmp->head = new_head;
}

std::string SickKoalaList::getContentName()
{
    if (this->koala)
        return this->koala->getName();
    return "[nullptr]";
}

SickKoalaList *SickKoalaList::removeUntilLast()
{
    SickKoalaList *tmp = this->head;
    if (!tmp)
        return nullptr;
    SickKoalaList *tmp_prev = nullptr;
    while (!tmp->isEnd())
    {
        if (tmp_prev)
        {
            tmp_prev->next = nullptr;
            tmp_prev->head = tmp_prev;
            tmp_prev->koala = nullptr;
        }
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    if (tmp_prev)
    {
        tmp_prev->next = nullptr;
        tmp_prev->head = tmp_prev;
        tmp_prev->koala = nullptr;
    }
    tmp->head = tmp;
    return tmp;
}

bool SickKoalaList::existsElement(SickKoalaList *element)
{
    for (SickKoalaList *tmp = this->head; tmp != nullptr; tmp = tmp->next)
        if (element == tmp)
            return true;
    return false;
}

SickKoalaList *SickKoalaList::getHead()
{
    return this->head;
}
