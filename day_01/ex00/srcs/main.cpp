#include <iostream>
#include "Pony.hpp"

void ponyOnTheHeap(std::string name)
{
	std::cout << "Enter in ponyOnTheHeap - nbInstance = " << Pony::getNbInst() << std::endl;
	Pony *pony = new Pony(name);
	std::cout << "ponyOnTheHeap - nbInstance = " << Pony::getNbInst() << std::endl;
	delete pony;
	std::cout << "Exit ponyOnTheHeap - nbInstance = " << Pony::getNbInst() << std::endl;
}

void ponyOnTheStack(std::string name)
{
	std::cout << "Enter in ponyOnTheStack - nbInstance = " << Pony::getNbInst() << std::endl;
	Pony pony = Pony(name);
	std::cout << "Exit ponyOnTheStack - nbInstance = " << Pony::getNbInst() << std::endl;
}

int main(void)
{
	std::cout << "Start main - nbInstance = " << Pony::getNbInst() << std::endl;

	ponyOnTheHeap("Happy");
	ponyOnTheStack("Angry");

	std::cout << "End main - nbInstance = " << Pony::getNbInst() << std::endl;
	return 0;
}
