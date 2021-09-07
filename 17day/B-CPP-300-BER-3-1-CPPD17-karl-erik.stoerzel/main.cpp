# include "ex02/OneTime.hpp"
# include "ex02/Cesar.hpp"
#include "ex04/Container.hpp"
# include <string>
# include <iostream>
#include <list>
#include <vector>
int main ()
{
    contain <char , std :: stack > test ;
    test . push ('t') ;
    test . aff () ;
    test . add () ;
    test . aff () ;
    contain <int , std :: vector > test2 ;
    test2 . push (1) ;
    test2 . aff () ;
    test2 . add () ;
    test2 . aff () ;
    return 0;
}
//static void encryptString ( IEncryptionMethod & encryptionMethod ,
//                            std :: string const & toEncrypt )
//{
//    size_t len = toEncrypt . size () ;
//    encryptionMethod . reset () ;
//    for ( size_t i = 0; i < len ; ++ i )
//    {
//        encryptionMethod . encryptChar ( toEncrypt [ i ]) ;
//    }
//    std :: cout << std :: endl ;
//}
//static void decryptString ( IEncryptionMethod & encryptionMethod ,
//                            std :: string const & toDecrypt )
//{
//    size_t len = toDecrypt . size () ;
//    encryptionMethod . reset () ;
//    for ( size_t i = 0; i < len ; ++ i )
//    {
//        encryptionMethod . decryptChar ( toDecrypt [ i ]) ;
//    }
//    std :: cout << std :: endl ;
//}
//int main ()
//{
//    Cesar c ;
//    OneTime o ("DedeATraversLesBrumes") ;
//    OneTime t ("TheCakeIsALie") ;
//    encryptString (c , "Je clair Luc, ne pas ? Ze woudrai un kekos !") ;
//    decryptString (c , "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !") ;
//    encryptString (c , "KIKOO") ;
////    encryptString (c , "LULZ XD") ;
//    decryptString (c , "Ziqivun ea Ndcsg.Wji !") ;
//    encryptString (t , "Prend garde Lion, ne te trompes pas de voie !") ;
//    encryptString (o , "De la musique et du bruit !") ;
//    encryptString (t , "Kion li faras? Li studas kaj programas !") ;
//    decryptString (t , "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !") ;
//    decryptString (o , "Gi pa dunmhmp wu xg tuylx !") ;
//    decryptString (t , "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla !") ;
//    return 0;
//}
