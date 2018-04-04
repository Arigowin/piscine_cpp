#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

    FragTrap copy(t);
    copy = g;

    ScavTrap pls("PLS");
    ScavTrap xyz("XYZ");

    d = pls.rangedAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.rangedAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.meleeAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.meleeAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.rangedAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.rangedAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.meleeAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.meleeAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.rangedAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.rangedAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.meleeAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.meleeAttack(pls.getName());
    pls.takeDamage(d);

     d = pls.rangedAttack(xyz.getName());
    xyz.takeDamage(d);
    d = xyz.rangedAttack(pls.getName());
    pls.takeDamage(d);

    d = pls.meleeAttack(xyz.getName()); // die
    xyz.takeDamage(d);

    xyz.beRepaired(50);
    xyz.beRepaired(50);
    xyz.beRepaired(50);

    pls.challengeNewcomer();
    pls.challengeNewcomer();
    pls.challengeNewcomer();

    ScavTrap copy2(pls);
    copy2 = xyz;
}
