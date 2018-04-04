#include <iostream>
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"

int main(void)
{
    {
        Character* zaz = new Character("zaz");

        std::cout << *zaz;

        Enemy* b = new RadScorpion();

        AWeapon* pr = new PlasmaRifle();
        AWeapon* pf = new PowerFist();

        zaz->equip(pr);
        std::cout << *zaz;
        zaz->equip(pf);

        zaz->attack(b);
        std::cout << *zaz;
        zaz->equip(pr);
        std::cout << *zaz;
        zaz->attack(b);
        std::cout << *zaz;
        zaz->attack(b);
        std::cout << *zaz;
    }
    {
        Character *thor = new Character("Thor");

        std::cout << *thor;

        Enemy* b = new RadScorpion();

        AWeapon* pr = new PlasmaRifle();
        AWeapon* pf = new PowerFist();

        thor->equip(pr);
        std::cout << *thor;
        thor->equip(pf);

        thor->attack(b);
        std::cout << *thor;
        thor->equip(pr);
        std::cout << *thor;
        thor->attack(b);
        std::cout << *thor;
        thor->attack(b);
        std::cout << *thor;

        thor->recoverAP();
        std::cout << *thor;

    }
    return 0;
}
