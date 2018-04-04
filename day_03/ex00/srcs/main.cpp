#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
    FragTrap t("Titi");
    FragTrap g("Grominet");

    int d = 0;

    d = t.rangedAttack(g.getName());
    g.takeDamage(d);
    d = g.rangedAttack(t.getName());
    t.takeDamage(d);

    d = t.meleeAttack(g.getName());
    g.takeDamage(d);
    d = g.meleeAttack(t.getName());
    t.takeDamage(d);

    d = t.rangedAttack(g.getName());
    g.takeDamage(d);
    d = g.rangedAttack(t.getName());
    t.takeDamage(d);

    d = t.meleeAttack(g.getName());
    g.takeDamage(d);
    d = g.meleeAttack(t.getName());
    t.takeDamage(d);

    d = t.rangedAttack(g.getName());
    g.takeDamage(d);
    d = g.rangedAttack(t.getName());
    t.takeDamage(d);

    d = t.meleeAttack(g.getName()); // Grominet die
    g.takeDamage(d);

    g.beRepaired(50);
    g.beRepaired(50);
    g.beRepaired(50);

    g.vaulthunter_dot_exe(t.getName());
    g.vaulthunter_dot_exe(t.getName());
    g.vaulthunter_dot_exe(t.getName());
    g.vaulthunter_dot_exe(t.getName());
    g.vaulthunter_dot_exe(t.getName());
    g.vaulthunter_dot_exe(t.getName());

    FragTrap x(t);
    x = g;
}
