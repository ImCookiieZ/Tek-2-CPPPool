/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** DomesticKoala.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_DOMESTICKOALA_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_DOMESTICKOALA_HPP

#include <vector>
#include <string>
#include "KoalaAction.hpp"

class DomesticKoala
{
    using methodPointer_t = void (KoalaAction::*)(const std::string &str);
    KoalaAction _action;
    std::vector<methodPointer_t> _allActions;
public:
    DomesticKoala() = delete;
    DomesticKoala(KoalaAction &action);
    DomesticKoala(const DomesticKoala &from);
    ~DomesticKoala() = default;

    DomesticKoala& operator=(const DomesticKoala &from);
    const std::vector<methodPointer_t> * getAction() const;
    void learnAction(unsigned  char command, methodPointer_t action);
    void unlearnAction(unsigned  char command);
    void doAction(unsigned char command, const std::string &param);
    void setKoalaAction(KoalaAction &from);
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_DOMESTICKOALA_HPP
