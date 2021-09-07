/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaNurse.cpp
*/

#include <fstream>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

void KoalaNurse::printStrWithNurse(std::string str) const
{
    std::cout << "Nurse " << this->ID << ": " << str << std::endl;
}

KoalaNurse::KoalaNurse(int id)
{
    working = false;
    this->ID = id;
}

KoalaNurse::~KoalaNurse()
{
    this->printStrWithNurse("Finally some rest!");
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    if (koala)
        koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string drug;
    std::string koala;
    std::ifstream file(filename);
    size_t pos;

    koala = filename;
    filename.clear();
    if (file)
    {
        pos = koala.find(this->reportEnfix);
        if (pos != std::string::npos && pos + this->reportEnfix.size() == koala.length() &&
            getline(file, drug))
        {
            koala = koala.replace(pos, 7, "\0");
            std::cout << "Nurse " << this->ID << ": Kreog! Mr.";
            std::cout << koala << " needs a " << drug << "!" << std::endl;
            return drug;
        }
    }
    return filename;
}

void KoalaNurse::timeCheck()
{
    if (this->working)
        this->printStrWithNurse("Time to go home to my eucalyptus forest!");
    else
        this->printStrWithNurse("Time to get to work!");
    this->working = !this->working;
}

long KoalaNurse::getID() const
{
    return this->ID;
}