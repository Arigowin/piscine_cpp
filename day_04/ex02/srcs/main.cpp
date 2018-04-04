#include <iostream>
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main(void)
{
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;
    ISquad *vlc2 = new Squad;
    ISquad *vlc = new Squad;

    vlc2->push(bob);
    vlc->push(bob);
    vlc2->push(jim);

    vlc = vlc2;

    delete vlc2;

    for (int i = 0; i < vlc->getCount(); ++i)
    {

        ISpaceMarine *cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;
    return 0;
}
