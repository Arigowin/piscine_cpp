#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main(void)
{
    {
        Sorcerer robert("Robert", "the Magnificent");
        Victim jim("Jimmy");
        Peon joe("Joe");
        std::cout << robert << jim << joe;
        robert.polymorph(jim);
        robert.polymorph(joe);
    }
    {
        Sorcerer *sorcerer = new Sorcerer("Robert", "The Magnificent");
        std::cout << *sorcerer;

        Victim *victim = new Victim("Gerard");

        std::cout << *victim;
        victim->getPolymorphed();

        sorcerer->polymorph(*victim);

        Victim *peon = new Peon("Nobodie");

        std::cout << *peon;
        peon->getPolymorphed();

        sorcerer->polymorph(*peon);
    }

    return 0;
}
