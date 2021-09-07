/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaNurseList.cpp
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *start)
{
    this->koalaNurse = start;
    this->next = nullptr;
    this->head = this;
}

bool KoalaNurseList::isEnd()
{
    return this->next == nullptr;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this->head;
    if (!tmp)
        return nullptr;
    while (tmp->next && (!tmp->koalaNurse || tmp->koalaNurse->getID() != id))
        tmp = tmp->next;
    if (tmp->next)
        return tmp->getContent();
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
{
    KoalaNurseList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (this == node)
    {
        this->setHeadToNext();
        return this->next;
    }
    else
    {
        while (tmp && tmp->next && tmp->next != node)
            tmp = tmp->next;
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return this->head;
}

void KoalaNurseList::append(KoalaNurseList *node)
{
    if (this->existsElement(node))
        return;
    KoalaNurseList *tmp = this;
    while (tmp->next)
        tmp = tmp->next;
    if (!this->head)
        this->head = node;
    else
        tmp->next = node;
    node->head = this->head;
    node->next = nullptr;
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (this->koalaNurse && this->koalaNurse->getID() == id)
    {
        this->setHeadToNext();
    }
    else
    {
        while (tmp->next)
        {
            if (tmp->next->koalaNurse && tmp->next->koalaNurse->getID() == id)
                break;
            tmp = tmp->next;
        }
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return this->head;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return this->koalaNurse;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return this->next;
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp = this->head;
    std::cout << "Nurses: ";
    while (tmp->next)
    {
        tmp->printContentID();
        std::cout << ", ";
        tmp = tmp->next;
    }
    if (tmp)
    {
        tmp->printContentID();
        std::cout << ".";
    }
    std::cout << std::endl;
}

void KoalaNurseList::setHeadToNext()
{
    KoalaNurseList *tmp = this->head;
    if (!tmp)
        return;
    KoalaNurseList *new_head = tmp->next;
    while (tmp->next)
    {
        tmp->head = new_head;
        tmp = tmp->next;
    }
    tmp->head = new_head;
}

void KoalaNurseList::printContentID()
{
    if (this->koalaNurse)
        std:: cout << this->koalaNurse->getID();
    else
        std::cout << "[nullptr]";
}

KoalaNurseList *KoalaNurseList::removeUntilLast()
{
    KoalaNurseList *tmp = this->head;
    if (!tmp)
        return nullptr;
    KoalaNurseList *tmp_prev = nullptr;
    while (!tmp->isEnd())
    {
        if (tmp_prev)
        {
            tmp_prev->next = nullptr;
            tmp_prev->head = tmp_prev;
            tmp_prev->koalaNurse = nullptr;
        }
        if (tmp->koalaNurse)
            tmp->koalaNurse->timeCheck();
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    if (tmp->koalaNurse)
        tmp->koalaNurse->timeCheck();
    if (tmp_prev)
    {
        tmp_prev->next = nullptr;
        tmp_prev->head = tmp_prev;
        tmp_prev->koalaNurse = nullptr;
    }
    tmp->head = tmp;
    return tmp;
}

bool KoalaNurseList::existsElement(KoalaNurseList *element)
{
    for (KoalaNurseList *tmp = this->head; tmp != nullptr; tmp = tmp->next)
        if (element == tmp)
            return true;
    return false;
}

KoalaNurseList *KoalaNurseList::getHead()
{
    return this->head;
}
