#include <iostream>
#include "Pony.hpp"

int Pony::_nbInst = 0;

Pony::Pony(std::string name)
{
	std::cout << "Create Pony: " + name << std::endl;
	this->name = name;
	Pony::_nbInst++;
}

Pony::~Pony(void)
{
	std::cout << "Delete Pony: " + this->name << std::endl;
	Pony::_nbInst--;
}

int Pony::getNbInst()
{
	return Pony::_nbInst;
}
