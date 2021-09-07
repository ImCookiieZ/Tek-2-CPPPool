/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** main.cpp
*/

#include "KoalaBot.hpp"

int main ()
{
    KoalaBot kb ;
    Arms p("arm1");
    p.informations();
    std :: cout << std :: boolalpha << kb . status () << std :: endl ;
    kb . informations();
    kb.swapParts(p);
    kb . informations();
    p.informations();
    return 0;
}