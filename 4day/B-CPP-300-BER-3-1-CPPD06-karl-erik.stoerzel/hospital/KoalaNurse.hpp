/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** KoalaNurse.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSE_HPP
#define B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSE_HPP

#include <string>
#include "SickKoala.hpp"

class KoalaNurse
{
private:
    std::string reportEnfix = ".report";
    bool working = false;
    int ID;
    void printStrWithNurse(std::string) const;
public:
    explicit KoalaNurse(int id);
    ~KoalaNurse();
    void giveDrug(std::string drug, SickKoala *koala);
    std::string readReport(std::string filename);
    void timeCheck();
    long getID() const;
};

#endif //B_CPP_300_BER_3_1_CPPD06_KARL_ERIK_STOERZEL_KOALANURSE_HPP