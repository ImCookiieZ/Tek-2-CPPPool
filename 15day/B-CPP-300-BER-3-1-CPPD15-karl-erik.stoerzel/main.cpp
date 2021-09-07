//# include <iostream>
//# include <string>
//# include "ex06/ex06.hpp"
//int main ()
//{
//{
//    int a = 2;
//    int b = 3;
//    :: swap (a , b ) ;
//    std :: cout << "a = " << a << ", b = " << b << std :: endl ;
//    std :: cout << "min(a, b) = " << :: min (a , b ) << std :: endl ;
//    std :: cout << "max(a, b) = " << :: max (a , b ) << std :: endl ;
//    std :: cout << "add(a, b) = " << :: add (a , b ) << std :: endl ;
//    std :: string c = "chaine1";
//    std :: string d = "chaine2";
//    :: swap (c , d ) ;
//    std :: cout << "c = " << c << ", d = " << d << std :: endl ;
//    std :: cout << "min(c, d) = " << :: min (c , d ) << std :: endl ;
//    std :: cout << "max(c, d) = " << :: max (c , d ) << std :: endl ;
//    std :: cout << "add(c, d) = " << :: add (c , d ) << std :: endl ;
//int tab [2] = {3 , 0};
//int minimum = templateMin ( tab , 2) ;
//std::cout << " templateMin (tab , 2) = " << minimum << std::endl ;
//minimum = nonTemplateMin ( tab , 2) ;
//std::cout << " nonTemplateMin (tab , 2) = " << minimum << std::endl ;
//    Tuple <float, char> t ;
//    t . a = 1.1f;
//    t . b = 'x';
//    std :: cout << t . toString () << std :: endl ;
//}
//# include "ex03/ex03.hpp"
//int main ()
//{
//    int tab [] = { 11 , 3 , 89 , 42 };
//    foreach ( tab , print <int > , 4) ;
//    std :: string tab2 [] = { "j'", " aime ", "les", " templates ", "!" };
//    foreach ( tab2 , print , 5) ;
//    return 0;
//}
//# include <iostream>
//# include "ex04/ex04.hpp"
//int main ()
//{
//    std :: cout << "1 == 0 ? " << equal (1 , 0) << std :: endl ;
//    std :: cout << "1 == 1 ? " << equal (1 , 1) << std :: endl ;
//    Tester <int > iT ;
//    std :: cout << "41 == 42 ? " << iT . equal (41 , 42) << std :: endl ;
//    std :: cout << "42 == 42 ? " << iT . equal (42 , 42) << std :: endl ;
//    return 0;
//}
#include "ex05/ex05.hpp"
int float_to_int ( float const & f ) {
    return static_cast <int >( f ) ;
}

class Inter
{
public:
    int i = 0;
};

int main()
{
//    array<int> f(2);
//    f.dump();
//    std::cout << f[2]<< std::endl;
//    f.dump();
    array<int> a(4);
    a[3] = 1;
    const auto b(a);
    b.dump();
    array<float> c;
    c.dump();
//    std::cout << c.size() << std::endl;
    c[2] = 1.1;
//    std::cout << c.size() << std::endl;
    c.dump();
    a = c.convertTo<int>(&float_to_int);
    a.dump();
}