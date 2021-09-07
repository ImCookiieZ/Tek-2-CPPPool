/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** main.cpp
*/

#include "KreogCom.hpp"

int main ()
{
    KreogCom k (42 , 42 , 101010) ;
    k . locateSquad () ;
    std::cout << std::endl;
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k . locateSquad () ;
    std::cout << std::endl;

    k.getCom()->ping();
    std::cout << std::endl;
//     k.removeCom();
//    KreogCom *tmp = k.getCom();
//    delete tmp;
//    k . locateSquad () ;
    std::cout << std::endl;
    return 0;
}