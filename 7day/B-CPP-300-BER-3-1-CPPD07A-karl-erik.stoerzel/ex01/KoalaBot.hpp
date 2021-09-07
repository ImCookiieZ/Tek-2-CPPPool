/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** KoalaBot.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KOALABOT_HPP
#define B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KOALABOT_HPP
#include "Parts.hpp"
class KoalaBot
{
private:
    std::string _serial = "Bob-01";
    Arms _arms;
    Legs _legs;
    Head _head;
public:
    explicit KoalaBot(const std::string& serial = "Bob-01");

    void setParts(const Parts &part);
    void swapParts(Arms &part);
    void swapParts(Legs &part);
    void swapParts(Head &part);
    void informations() const;
    bool status() const;
};

#endif //B_CPP_300_BER_3_1_CPPD07A_KARL_ERIK_STOERZEL_KOALABOT_HPP
