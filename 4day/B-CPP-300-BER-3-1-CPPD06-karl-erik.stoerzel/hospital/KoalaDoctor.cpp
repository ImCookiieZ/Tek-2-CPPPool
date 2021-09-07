/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaDoctor.cpp
*/

#include <fstream>
#include "KoalaDoctor.hpp"
#include <list>

void KoalaDoctor::printStrWithDoctor(std::string str) const
{
    std::cout << "Dr." << this->name << ": " << str << std::endl;
}

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->printStrWithDoctor("I'm Dr." + this->name + "! How do you kreog?");
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    if (!patient)
        return;
    std::string patient_name = patient->getName();
    std::ofstream file(patient_name + ".report");
    std::string drugs[] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};

    this->printStrWithDoctor("So what's goerking you Mr." + patient_name + "?");
    patient->poke();
    if (file)
    {
        file << drugs[random() % 5];
        file.close();
    }
}

void KoalaDoctor::timeCheck()
{
    if (this->working)
        this->printStrWithDoctor("Time to go home to my eucalyptus forest!");
    else
        this->printStrWithDoctor("Time to get to work!");
    this->working = !this->working;
}

std::string KoalaDoctor::getName()
{
    return this->name;
}