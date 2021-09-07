/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD07A_karl_erik_stoerzel
** File description:
** main.cpp
*/

#include "Phaser.hpp"
#include "Sounds.hpp"
const std::string Sounds::Rocket = "BOOM";
const std::string Sounds::Regular = "lol";
const std::string Sounds::Plasma = "nice";
int main ()
{
    Phaser p ;
    std::cout << p.getCurrentAmmos();
    p . fire () ;
    p . reload () ;
    std :: cout << " Firing all ammunition " << std :: endl ;
    while ( p . getCurrentAmmos () > 0)
        p . fire () ;
    p . fire () ;
    p.addAmmo(Phaser::REGULAR);
    p.changeType(Phaser::PLASMA);
    p.reload();
    while ( p . getCurrentAmmos () > 2)
        p . fire () ;
    p.addAmmo(Phaser::REGULAR);
    p.addAmmo(Phaser::REGULAR);
    p.ejectClip();
    p . fire () ;
    p.reload();
    while ( p . getCurrentAmmos () > 0)
        p . fire () ;
    p . fire () ;

    return 0;
}