/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** Hospital.cpp
*/

#include "Hospital.hpp"

void Hospital::addDoctor(KoalaDoctorList *newDoctor)
{
    if (this->doctor_list)
    {
        if (!this->doctor_list->existsElement(newDoctor))
            this->doctor_list->append(newDoctor);
    }
    else
    {
        this->doctor_list = newDoctor;
    }
}

void Hospital::addSick(SickKoalaList *newKoala)
{
    if (this->koala_list)
    {
        if (!this->koala_list->existsElement(newKoala))
            this->koala_list->append(newKoala);
    }
    else
    {
        this->koala_list = newKoala;
    }
}

void Hospital::addNurse(KoalaNurseList *newNurse)
{
    if (this->nurse_list)
    {
        if (!this->nurse_list->existsElement(newNurse))
            this->nurse_list->append(newNurse);
    }
    else
    {
        this->nurse_list = newNurse;
    }
}

void Hospital::letDoctorsWork() const
{
    KoalaDoctorList *tmpDoctorElement = this->doctor_list;
    KoalaDoctor *tmpDoctor = nullptr;

    while (tmpDoctorElement)
    {
        tmpDoctor = tmpDoctorElement->getContent();
        std::cout << "[HOSPITAL] Doctor " << tmpDoctorElement->getContentName() << " just arrived!" << std::endl;
        if (tmpDoctor)
            tmpDoctor->timeCheck();
        tmpDoctorElement = tmpDoctorElement->getNext();
    }
}

void Hospital::letPatientsArrive() const
{
    SickKoalaList *tmpPatientElement = this->koala_list;

    while (tmpPatientElement)
    {
        std::cout << "[HOSPITAL] Patient " << tmpPatientElement->getContentName() << " just arrived!" <<
        std::endl;
        tmpPatientElement = tmpPatientElement->getNext();
    }
}

void Hospital::letNursesWork() const
{
    KoalaNurseList *tmpNurseElement = this->nurse_list;
    KoalaNurse *tmpNurse = nullptr;

    while (tmpNurseElement)
    {
        tmpNurse = tmpNurseElement->getContent();
        std::cout << "[HOSPITAL] Nurse ";
        tmpNurseElement->printContentID();
        std::cout << " just arrived!" << std::endl;
        if (tmpNurse)
            tmpNurse->timeCheck();
        tmpNurseElement = tmpNurseElement->getNext();
    }
}

void Hospital::run()
{
    this->letDoctorsWork();
    this->letPatientsArrive();
    this->letNursesWork();

    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    if (this->doctor_list)
        this->doctor_list->dump();
    if (this->nurse_list)
        this->nurse_list->dump();
    if (this->koala_list)
        this->koala_list->dump();

    std::cout << std::endl;
    patientTreatment();

    if (this->nurse_list)
        this->nurse_list = this->nurse_list->removeUntilLast();
    if (this->doctor_list)
        this->doctor_list = this->doctor_list->removeUntilLast();
    if (this->koala_list)
        this->koala_list = this->koala_list->removeUntilLast();
}

void Hospital::patientTreatment() const
{
    SickKoalaList *tmpPatientElement = koala_list;
    KoalaDoctorList *tmpDoctorElement = doctor_list;
    KoalaNurseList *tmpNurseElement = nurse_list;
    SickKoala *tmpKoala;
    KoalaNurse *tmpNurse;
    KoalaDoctor *tmpDoctor;
    std::string drug;

    while (tmpPatientElement)
    {
        if (!tmpPatientElement)
            return;
        tmpKoala = tmpPatientElement->getContent();
        while (tmpPatientElement && !tmpKoala)
        {
            tmpPatientElement = tmpPatientElement->getNext();
            tmpKoala = tmpPatientElement->getContent();
        }
        if (!tmpPatientElement)
            return;
        if (!tmpNurseElement)
            return;
        tmpNurse = tmpNurseElement->getContent();
        while (tmpNurseElement && !tmpNurse)
        {
            tmpNurseElement = tmpNurseElement->getNext();
            tmpNurse = tmpNurseElement->getContent();
        }
        if (!tmpNurseElement)
            return;
        if (!tmpDoctorElement)
            return;
        tmpDoctor = tmpDoctorElement->getContent();
        while (tmpDoctorElement && !tmpDoctor)
        {
            tmpDoctorElement = tmpDoctorElement->getNext();
            tmpDoctor = tmpDoctorElement->getContent();
        }
        if (!tmpDoctorElement)
            return;
        tmpDoctor = tmpDoctorElement->getContent();
        tmpNurse = tmpNurseElement->getContent();
        tmpDoctor->diagnose(tmpKoala);
        drug = tmpNurse->readReport(tmpKoala->getName() + ".report");
        tmpKoala->takeDrug(drug);
        if (tmpDoctorElement->isEnd())
            tmpDoctorElement = tmpDoctorElement->GetHead();
        else
            tmpDoctorElement = tmpDoctorElement->getNext();
        if (tmpNurseElement->isEnd())
            tmpNurseElement = tmpNurseElement->getHead();
        else
            tmpNurseElement = tmpNurseElement->getNext();
        tmpPatientElement = tmpPatientElement->getNext();
    }
}
