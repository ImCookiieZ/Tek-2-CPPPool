#include <iostream>

//# include <cstdlib>
//# include "ex01/EventManager.hpp"
//static void populateEvents ( EventManager & em )
//{
//em . addEvent ( Event (10 , "Eat ") ) ;
//em . addEvent ( Event (12 , " Finish the exercises ") ) ;
//em . addEvent ( Event (12 , " Understand the thing ") ) ;
//em . addEvent ( Event (15 , "Set the rights ") ) ;
//em . addEvent ( Event (8 , "Ask what the hell a const_iterator is") ) ;
//em . addEvent ( Event (11 , " Wash my hands so that my keyboard doesn't smell like kebab ") ) ;
//}
//int main ()
//{
//    std :: list < Event > todo;
//    todo . push_front ( Event (19 , "The vengeance of the Koala ") ) ;
//    todo . push_front ( Event (19 , "The return of the vengeance of the Koala ") ) ;
//    todo . push_front ( Event (19 , "The come back of the vengeance of the Koala ") ) ;
//    todo . push_front ( Event (19 , "The sequel to the vengeance .") ) ;
//    todo . push_front ( Event (19, " What the hell do you mean 'this morning ' ?!") ) ;
//    todo . push_front ( Event (19, "No , no , you 're pushing it now ... ") ) ;
//    std::list<Event>::iterator it = todo.begin();
//    std::list<Event>::iterator end = todo.end();
//    while (it != end)
//    {
//        std::cout << it->getEvent() << std::endl;
//        it++;
//    }
//    EventManager em ;
//    populateEvents ( em ) ;
//    em . dumpEvents () ;
//    std :: cout << " ===== " << std :: endl ;
////    // Following a massive rotten leaves of eucalyptus ingestion , all the
////    //exercises of the day are canceled .
//    em . removeEventsAt (12) ;
//    em . dumpEvents () ;
//    std :: cout << " ===== " << std :: endl ;
////    // Hey , the time is flying !
//    em . addTime (10) ;
//    std :: cout << " ===== " << std :: endl ;
//    em . dumpEvents () ;
//    std :: cout << " ===== " << std :: endl ;
////    // Following the aforementioned ingestion and to help you improve your skill
////    //level , an exercises serie will be added .
//    em . addEventList ( todo ) ;
//    em . dumpEvents () ;
//    std :: cout << " ===== " << std :: endl ;
////    // I forgot something , but what ??
//    em . dumpEventAt (15) ;
////   // 6
//    std :: cout << " ===== " << std :: endl ;
////    // And we finish the day with joy and good humour .
//    em . addTime (14) ;
//    return 0;
//}
//#include "ex02/BF_Translator.hpp"
//int main()
//{
//    BF_Translator tr;
//    std::cout << tr.translate("test.txt", "test2.c");
//}
//#include "ex03/Ratatouille.hpp"
//int main ()
//{
//    Ratatouille rata ;
//    rata . addSauce ("Tomato") . addCondiment (42) . addSpice (123.321) ;
//    rata . addVegetable ('x') ;
//    std :: cout << "We taste: " << rata . kooc () << std :: endl ;
//    rata . addSauce ("Bolognese") ;
//    rata . addSpice (3.14) ;
//    std :: cout << "C'mon, taste that: " << rata . kooc () << std :: endl ;
//    // C'mon , gimme your pot , i'll just take a bit of it and try something else
//    Ratatouille glurp ( rata ) ;
//    glurp . addVegetable ('p') ;
//    glurp . addVegetable ('o') ;
//    glurp . addSauce ("Tartar") ;
//    std :: cout << "And now: " << glurp . kooc () << std :: endl ;
//    // Looks good ...
//    rata = glurp ;
//    std :: cout << "I'll taste again, it's sooo good: " << rata . kooc () << std :: endl;
//    std :: cout << "I'll taste again, it's sooo good: " << glurp . kooc () << std :: endl
//        ;
//    return 0;
//}
//# include <iostream>
//# include "ex04/Parser.hpp"
//int main ()
//{
//    Parser p ;
//    p . feed (" ((12*2) +14) ") ;
//    std :: cout << p . result () << std :: endl ;
//    p . feed (" ((17 % 9) / 4)") ;
//    std :: cout << p . result () << std :: endl ;
//    p . reset () ;
//    p . feed ("(17 - (4 * 13))") ;
//    std :: cout << p . result () << std :: endl ;
//    p . feed (" (((133 / 5) + 6) * ((45642 % 127) - 21))") ;
//    std :: cout << p . result () << std :: endl ;
//    return 0;
//}
#include "ex05/MutantStack.hpp"
#include <list>
int main ()
{
    MutantStack<int>::iterator it;
    MutantStack<int> mstack ;
    mstack . push(5) ;
    mstack . push(17) ;
    std :: cout << mstack . top () << std :: endl ;
    mstack . pop() ;
    std :: cout << mstack . top () << std :: endl << std::endl;
    mstack . push(3) ;
    mstack . push(5) ;
    mstack . push(737) ;
    mstack . push(0) ;
    it = mstack .begin() ;
    MutantStack<int>::iterator end_it = mstack .end () ;
    ++it;
    --it;
    while ( it != end_it )
    {
        std :: cout << * it << std :: endl ;
        ++ it ;
    }
    std::cout << std::endl;
    std::list<int>::iterator it2;
    std::list<int> mstack2 ;
    mstack2 . push_front(5) ;
    mstack2 . push_front(17) ;
    std :: cout << mstack2 . front() << std :: endl ;
    mstack2 . pop_front() ;
    std :: cout << mstack2 . front() << std :: endl << std::endl;
    mstack2 . push_front(3) ;
    mstack2 . push_front(5) ;
    mstack2 . push_front(737) ;
    mstack2 . push_front(0) ;
    it2 = mstack2 .begin() ;
    std::list<int>::iterator end_it2 = mstack2 .end () ;
    ++it2;
    --it2;
    while ( it2 != end_it2 )
    {
        std :: cout << * it2 << std :: endl ;
        ++ it2 ;
    }
    return 0;
}