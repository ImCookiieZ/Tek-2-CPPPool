/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaDoctorList.cpp
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *start)
{
    this->doctor = start;
    this->next = nullptr;
    this->head = this;
}

bool KoalaDoctorList::isEnd()
{
    return this->next == nullptr;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this->head;
    if (!tmp)
        return nullptr;
    while (tmp->next && (!tmp->doctor || tmp->doctor->getName() != name))
        tmp = tmp->next;
    if (tmp->next)
        return tmp->getContent();
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
{
    KoalaDoctorList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (this == node)
    {
        this->setHeadToNext();
        return this->next;
    }
    else
    {
        while (tmp->next && tmp->next != node)
            tmp = tmp->next;
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return this->head;
}

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    if (this->existsElement(node))
        return;
    KoalaDoctorList *tmp = this;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    if (!this->head)
        this->head = node;
    else
        tmp->next = node;
    node->head = this->head;
    node->next = nullptr;
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *tmp = this->head;
    if (!tmp)
        return nullptr;
    if (this->doctor && this->doctor->getName() == name)
    {
        this->setHeadToNext();
    }
    else
    {
        while (tmp->next)
        {
            if (tmp->next->doctor && tmp->next->doctor->getName() == name)
                break;
            tmp = tmp->next;
        }
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return this->head;
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return this->doctor;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return this->next;
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp = this->head;
    std::cout << "Doctors: ";
    while (tmp && tmp->next)
    {
        std::cout << tmp->getContentName() << ", ";
        tmp = tmp->next;
    }
    if (tmp)
        std::cout << tmp->getContentName() << ".";
    std::cout << std::endl;
}

void KoalaDoctorList::setHeadToNext()
{
    KoalaDoctorList *tmp = this->head;
    if (!tmp)
        return;
    KoalaDoctorList *new_head = tmp->next;
    while (tmp->next)
    {
        tmp->head = new_head;
        tmp = tmp->next;
    }
    tmp->head = new_head;
}

std::string KoalaDoctorList::getContentName()
{
    if (this->doctor)
        return this->doctor->getName();
    return "[nullptr]";
}

KoalaDoctorList *KoalaDoctorList::removeUntilLast()
{
    KoalaDoctorList *tmp = this->head;
    if (!tmp)
        return nullptr;
    KoalaDoctorList *tmp_prev = nullptr;
    while (!tmp->isEnd())
    {
        if (tmp_prev)
        {
            tmp_prev->next = nullptr;
            tmp_prev->head = tmp_prev;
            tmp_prev->doctor = nullptr;
        }
        if (tmp->doctor)
            tmp->doctor->timeCheck();
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    if (tmp->doctor)
        tmp->doctor->timeCheck();
    if (tmp_prev)
    {
        tmp_prev->next = nullptr;
        tmp_prev->head = tmp_prev;
        tmp_prev->doctor = nullptr;
    }
    tmp->head = tmp;
    return tmp;
}

bool KoalaDoctorList::existsElement(KoalaDoctorList *element)
{
    for (KoalaDoctorList *tmp = this->head; tmp; tmp = tmp->next)
    {
        if (element == tmp)
            return true;
    }
    return false;
}

KoalaDoctorList *KoalaDoctorList::GetHead()
{
    return this->head;
}
