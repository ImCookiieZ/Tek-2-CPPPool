#include <iostream>
#include <memory>
//#include "ex00/Sorcerer.hpp"

//int main ()
//{
//    Sorcerer robert ("Robert", "the Magnificent") ;
//    Victim jim ("Jimmy") ;
//    Peon joe ("Joe") ;
//    std :: cout << robert << jim << joe ;
//    robert . polymorph ( jim ) ;
//    robert . polymorph ( joe ) ;
//    return 0;
//}

//#include "ex01/Character.hpp"
//#include "ex01/PlasmaRifle.hpp"
//#include "ex01/RadScorpion.hpp"
//#include "ex01/PowerFist.hpp"
//#include "ex02/ISquad.hpp"
//#include "ex02/Squad.hpp"
//#include "ex02/TacticalMarine.hpp"
//#include "ex02/AssaultTerminator.hpp"
//int main ()
//{
//    const auto preda = new Character ("Predator") ;
//    const auto prey = new RadScorpion () ;
//    std :: cout << * preda ;
//    AWeapon * pr (new PlasmaRifle () ) ;
//    AWeapon * pf (new PowerFist () ) ;
//    preda -> equip ( pr ) ;
//    std :: cout << * preda ;
//    preda -> equip ( pf ) ;
//    preda -> attack ( prey ) ;
//    std :: cout << * preda ;
//    preda -> equip ( pr ) ;
//    std :: cout << * preda ;
//    preda -> attack ( prey ) ;
//    std :: cout << * preda ;
//    preda -> attack (nullptr ) ;
//    std :: cout << * preda ;
//    return 0;
//}

//int main ()
//{
//    std::unique_ptr<ISquad> vlc (new Squad());
//    Squad test;
//    test . push (nullptr ) ;
//    vlc -> push (new TacticalMarine ) ;
////    Squad test = vlc;
//    vlc -> push (nullptr ) ;
//    test = *vlc;
//    delete vlc;
//    for (int i = 0; i < test . getCount () ; ++ i ) {
//        const auto cur = test .getUnit ( i ) ;
//        cur -> battleCry () ;
//        cur -> rangedAttack () ;
//        cur -> meleeAttack () ;
//    }
////    const auto cur = test.getUnit(1);
////    cur -> battleCry () ;
////    cur -> rangedAttack () ;
////    cur -> meleeAttack () ;
////    std::cout << vlc.getCount();
////    delete test;
////    for (int i = 0; i < vlc -> getCount () ; ++ i ) {
////        const auto cur = vlc -> getUnit ( i ) ;
////        cur -> battleCry () ;
////        cur -> rangedAttack () ;
////        cur -> meleeAttack () ;
////        delete cur;
////    }
//    return 0;
//}


#include "ex03/MateriaSource.hpp"
#include "ex03/Ice.hpp"
#include "ex03/Cure.hpp"
#include "ex03/Character.hpp"
int main ()
{
//    auto *c = new Character("nice");
//    std :: unique_ptr < ICharacter > k(c);
    IMateriaSource * src (new MateriaSource () ) ;
    src -> learnMateria (new Ice ) ;
    src -> learnMateria (new Cure ) ;
    std::unique_ptr<ICharacter>perceval(new Character("Perceval")) ;
    auto tmp = src -> createMateria ("ice") ;
    perceval -> equip ( tmp ) ;
    tmp = src -> createMateria ("cure") ;
    perceval -> equip ( tmp ) ;
    std :: unique_ptr < ICharacter > bohort (new Character ("Bohort") ) ;
//    std::cout << "test\n";
    perceval -> use (0 , * bohort ) ;
    perceval -> use (0 , * bohort ) ;
//    std::cout << "test\n";
    perceval -> use (1 , * bohort ) ;
    perceval -> use (1 , * bohort ) ;
    std::cout << tmp->getXP();
    return 0;
}