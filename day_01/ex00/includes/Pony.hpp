#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
public:
	std::string name;

	Pony(std::string name);
	~Pony(void);

	static int getNbInst();

private:
	static int _nbInst;
};

#endif // PONY_HPP
