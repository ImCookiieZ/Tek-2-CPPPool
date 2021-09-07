#include <iostream>

//# include "ex00/Toy.hpp"
//int main ()
//{
////    Picture p1("");
//    Toy p2;
////    p2.getPictureFromFile("");
////    std::cout << p1.data << std::endl;
//    std::cout << p2.getAscii() << std::endl;
//    Toy toto ;
//    Toy ET ( Toy :: ALIEN , "", "") ;
//    toto . setName ("TOTO!") ;
//    if ( toto . getType () == Toy :: BASIC_TOY )
//        std :: cout << "basic toy: " << toto . getName () << std :: endl
//                    << toto . getAscii () << std :: endl ;
//    if ( ET . getType () == Toy :: ALIEN )
//        std :: cout << "this alien is: " << ET . getName () << std :: endl
//                    << ET . getAscii () << std :: endl ;
//    ET.setAscii("rex.txt");
//    if ( ET . getType () == Toy :: ALIEN )
//        std :: cout << "this alien is: " << ET . getName () << std :: endl
//                    << ET . getAscii () << std :: endl ;
//    return 0;
//}

//# include <iostream>
//# include <memory>
//# include "ex03/Toy.hpp"
//# include "ex03/Buzz.hpp"
//# include "ex03/Woody.hpp"
//int main ()
//{
//    std :: unique_ptr < Toy > b (new Buzz ("buzziiiii") ) ;
//    std :: unique_ptr < Toy > w (new Woody ("wood") ) ;
//    std :: unique_ptr < Toy > t (new Toy ( Toy :: ALIEN , "ET", " alien.txt") ) ;
//    b -> speak ("To the code, and beyond !!!!!!!!") ;
//    w -> speak ("There's a snake in my boot.") ;
//    t -> speak ("the claaaaaaw") ;
//}

//# include <iostream>
//# include "ex04/Toy.hpp"
//#include "ex04/Buzz.hpp"
//int main ()
//{
////    Buzz *b = new Buzz("nice");
////    Buzz c(*b);
////    delete b;
////    std::cout << c.getAscii() << std::endl << c.getName();
//    Toy a ( Toy :: BASIC_TOY , "REX", "rex.txt") ;
//    std :: cout << a ;
//    a << "\\o/";
//    std :: cout << a ;
//}

//# include <iostream>
//# include "ex05/Toy.hpp"
//# include "ex05/Buzz.hpp"
//# include "ex05/Woody.hpp"
//int main ()
//{
//    Woody w (" wood ") ;
//    auto z = w . getLastError () ;
//    std :: cout << " Error in " << z . where () << ": " << z . what () <<
//                std :: endl ;
//    if ( w . setAscii (" file_who_does_not_exist .txt ") == false )
//    {
//        auto e = w . getLastError () ;
//        if ( e . type == Toy :: Error :: PICTURE )
//        {
//            std :: cout << " Error in " << e . where () << ": " << e . what () <<
//                        std :: endl ;
//        }
//    }
//    if ( w . speak_es (" Woody does not have spanish mode ") == false )
//    {
//        auto e = w . getLastError () ;
//        if ( e . type == Toy :: Error :: SPEAK )
//        {
//            std :: cout << " Error in " << e . where () << ": " << e . what () <<
//                        std :: endl ;
//        }
//    }
//    if ( w . speak_es (" Woody does not have spanish mode ") == false )
//    {
//        auto e = w . getLastError () ;
//        if ( e . type == Toy :: Error :: SPEAK )
//        {
//            std :: cout << " Error in " << e . where () << ": " << e . what () <<
//                        std :: endl ;
//        }
//    }
//}

# include <iostream>
# include "ex06/Toy.hpp"
# include "ex06/ToyStory.hpp"
# include "ex06/Buzz.hpp"
# include "ex06/Woody.hpp"
int main ()
{

    Buzz b ("buzzi") ;
    Woody w ("wood") ;
    std::cout << ToyStory :: tellMeAStory ("superStory.txt", b , & Toy :: speak_es , w , & Toy ::
    speak ) ;
}