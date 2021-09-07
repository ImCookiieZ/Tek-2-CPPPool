#include <iostream>
#include "Warrior.hpp"
#include "Hunter.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "Mage.hpp"
int main ()
{
    Character c ("poney", 42) ;
    c . TakeDamage (50) ;
    c . TakeDamage (200) ;
    c . TakeDamage (200) ;
    Warrior w ("Thor", 42, "bow");
    w.CloseAttack();
    w.RangeAttack();
    Hunter h ("thor", 42);
    h.CloseAttack();
    h.RangeAttack();
    Paladin bibi("bibi", 42);
    h.getPower();
    h.getPv();
    h.Heal();
}
