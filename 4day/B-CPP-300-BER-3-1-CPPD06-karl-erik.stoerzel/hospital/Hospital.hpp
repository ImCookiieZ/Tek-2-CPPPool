/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** Hospital.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_HOSPITAL_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_HOSPITAL_HPP

#include "SickKoalaList.hpp"
#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"

class Hospital
{
private:
    SickKoalaList *koala_list = nullptr;
    KoalaNurseList *nurse_list = nullptr;
    KoalaDoctorList *doctor_list = nullptr;
public:
    void addDoctor(KoalaDoctorList *doctor);
    void addSick(SickKoalaList *koala);
    void addNurse(KoalaNurseList *nurse);
    void run();
    void letDoctorsWork() const;
    void letNursesWork() const;
    void letPatientsArrive() const;

    void patientTreatment() const;
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_HOSPITAL_HPP
