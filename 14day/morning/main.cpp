//#include <iostream>
//#include "ex00/Lemon.hpp"
//#include "ex00/Banana.hpp"
//#include "ex00/FruitBox.hpp"
//int main()
//{
//        Lemon l ;
//        Banana b ;
//        std :: cout << l . getVitamins () << std :: endl ;
//        std :: cout << b . getVitamins () << std :: endl ;
//        std :: cout << l . getName () << std :: endl ;
//        std :: cout << b . getName () << std :: endl ;
//        Fruit & f = l ;
//        std :: cout << f . getVitamins () << std :: endl ;
//        std :: cout << f . getName () << std :: endl ;
//        std::cout << std::endl;
//        FruitBox *fb = new FruitBox(1);
////        std::cout << fb.putFruits(&l) << std::endl;
////        std::cout << fb.putFruits(&l) << std::endl;
////        std::cout << fb.putFruits(&b) << std::endl;
//        std::cout << fb->nbFruits() << std::endl;
//        delete fb;
//        return 0;
//}

//#include <iostream>
//#include "ex00/Lemon.hpp"
//#include "ex00/Banana.hpp"
//#include "ex00/FriutBox.hpp"
//int main()
//{
//    Lemon j;
//        Lemon l ;
//        Banana b ;
//        FruitBox fb(10);
//
//        std::cout << fb.putFruits(&l) << std::endl;
//        std::cout << fb.putFruits(&l) << std::endl;
//        std::cout << fb.putFruits(&b) << std::endl;
//        return 0;
//}
#include "ex01/Lemon.hpp"
#include "ex01/Banana.hpp"
#include "ex01/FruitBox.hpp"
#include "ex01/LittleHand.hpp"
#include "ex01/Lime.hpp"

int main ()
{
    Fruit *f1;
    Fruit *f2;
    Fruit *f3;
    Fruit *f4;
    Fruit *f5;
    auto *l = new Lemon;
    auto *b = new Banana;
    auto *n = new Lemon;
    auto *m = new Lime;
    auto *t = new Lime;
    FruitBox list(5);
    FruitBox lemons(1);
    FruitBox bananas(2);
    FruitBox limes(2);
    list.putFruit(l);
    list.putFruit(b);
    list.putFruit(n);
    list.putFruit(m);
    list.putFruit(t);
//    FruitNode *tmp = list.head();
//    std::cout << list.nbFruits() << std::endl;
//    while (tmp)
//    {
//        std::cout << tmp->_fruit->getName() << std::endl;
//        tmp = tmp->next;
//    }

    LittleHand::sortFruitBox(list,lemons,bananas,limes);
//    FruitNode *tmp = list.head();
//        std::cout << list.nbFruits() << std::endl;
//        while (tmp)
//        {
//            std::cout << tmp->_fruit->getName() << std::endl;
//            tmp = tmp->next;
//        }
//
    f1 = list.pickFruit();
    f2 = lemons.pickFruit();
    f3 = bananas.pickFruit();
    *f3 = *f1;
    f4 = limes.pickFruit();
    f5 = limes.pickFruit();
    std::cout << f1->getName () << std::endl ;
    std::cout << f2->getName () << std::endl ;
    std::cout << f3->getName () << std::endl ;
    std::cout << f4->getName () << std::endl ;
    std::cout << f5->getName () << std::endl ;
    return 0;
}