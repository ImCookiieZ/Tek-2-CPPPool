#include <iostream>
#include <cassert>
#include "ex04/RefPtr.hpp"
class test : public BaseComponent
{
    int nice;
};
int main()
{
    RefPtr oxygenator = new test ;
    BaseComponent * raw = oxygenator . get () ;
    RefPtr other ( raw ) ;
    RefPtr useless ;
    RefPtr lastOne ;
    lastOne = other ;
    assert(lastOne . get () == raw ) ;
    ( void ) useless ;
    throw std :: runtime_error ("An error occured here !") ;
    return 0;
}
