/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** main.cpp
*/

#include "hospital/Hospital.hpp"

int main ( void )
{
    srandom (42) ;
    KoalaDoctor cox ("Belga");
    KoalaDoctor cox2 ("Bsdhfuiasfiub");
    KoalaDoctor house ("");
    KoalaDoctor tired ("Nau");
    KoalaDoctor fourth("Kevin");

    KoalaDoctorList test(&fourth);
    KoalaDoctorList coxList (&cox);
    KoalaDoctorList houseList(nullptr);
    KoalaDoctorList tiredLust2(&cox2);
    KoalaDoctorList tiredLust(&tired);
    KoalaDoctorList tiredLust3(&cox2);
    KoalaDoctorList huhu(&house);

    test.append(&test);
    test.append(&houseList);
    test.append(&tiredLust2);
    test.append(&tiredLust3);
    test.append(&coxList);
    test.append(&huhu);
    test.append(&houseList);
    test.append(&tiredLust);
    test.removeFromName("");
    test.dump();
//    test.removeFromName(tiredLust.getContentName());
//    test.remove(&tiredLust2);
//    test.getContentName();
//    test.getContent();
//    test.getNext();
    KoalaDoctor * test10 = test.getFromName("");
//    std::cout << test10->getName();
    test.removeFromName(" j");
    test.removeFromName("Nau");
    test.remove(nullptr);
    test.removeFromName("Nau");
    test.dump();
//    KoalaDoctorList doc1 (& cox ) ;
//    KoalaDoctorList doc2 (& house ) ;
//    KoalaDoctorList doc3 (& tired ) ;
//    KoalaNurse ratched (1) ;
//    KoalaNurse betty (2) ;
//    KoalaNurseList nurse1 (& ratched ) ;
//    KoalaNurseList nurse2 (& betty ) ;
//    SickKoala cancer (" Ganepar ") ;
//    SickKoala gangrene (" Scarface ") ;
//    SickKoala measles (" RedFace ") ;
//    SickKoala smallpox (" Varia ") ;
//    SickKoala fracture (" Falter ") ;
//    SickKoalaList sick1 (nullptr ) ;
//    SickKoalaList sick4 (& gangrene ) ;
//    SickKoalaList sick3 (& measles ) ;
//    SickKoalaList sick2 (& smallpox ) ;
//    SickKoalaList sick5 (& fracture ) ;
//    {
//        Hospital bellevue ;
////        bellevue . addDoctor (& doc1 ) ;
////        bellevue . addDoctor (& doc2 ) ;
////        bellevue . addDoctor (& doc3 ) ;
////        bellevue . addSick (& sick1 ) ;
////        bellevue . addSick (& sick2 ) ;
////        bellevue . addSick (& sick3 ) ;
////        bellevue . addSick (& sick4 ) ;
////        bellevue . addSick (& sick5 ) ;
////        bellevue . addNurse (& nurse1 ) ;
////        bellevue . addNurse (& nurse2 ) ;
////        bellevue . addSick (& sick4 ) ;
//        bellevue . run () ;
//    }
//    if( nurse1 . isEnd () && sick1 . isEnd () && doc1 . isEnd () )
//        std :: cout << " Lists cleaned up." << std :: endl ;
//    else
//        std :: cerr << "You fail ! Boo !" << std :: endl ;
    return (0) ;
}