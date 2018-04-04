#include <iostream>
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("Nobody", 100, 50, 20, 15, 3)
{
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 120, 60, 5, 0)
{
    std::cout << this->_name << ": Can I shoot something now? Or climb some stairs? SOMETHING exciting?" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout << this->_name << ": Oh. My. God. What if I'm like... a fish? And, if I'm not moving... I stop breathing? AND THEN I'LL DIE! HELP ME! HELP MEEEEE HEE HEE HEEE! HHHHHHHELP!" << std::endl;
}

int NinjaTrap::rangedAttack(std::string const &target)
{
    int i = ClapTrap::rangedAttack();
    std::cout << "NINJA-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage" << std::endl;
    return i;
}

int NinjaTrap::meleeAttack(std::string const &target)
{
    int i = ClapTrap::meleeAttack();
    std::cout << "NINJA-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage" << std::endl;
    return i;
}

void NinjaTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    std::cout << this->_name << ": That looks like it hurts! HP: " << this->_hintPoints << std::endl;
}

void NinjaTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << this->_name << ": YEAH ! Healing me ! HP: " << this->_hintPoints << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
    std::cout << "Step right up, to the Bulletnator 9000!" << std::endl;
    int d = this->meleeAttack(target.getName());
    target.takeDamage(d);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
    std::cout << "Something eating you?" << std::endl;
    target.takeDamage(50);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
    std::cout << "My friend " << target.getName() << " I heal you" << std::endl;
    target.beRepaired(100);
}
