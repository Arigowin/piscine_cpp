#include <sstream>
#include "Human.hpp"
#include "Brain.hpp"


Human::Human(){
}

Human::~Human()
{
}

std::string Human::identify() const
{
    return this->getBrain().identify();
}

Brain const &Human::getBrain() const
{
    return this->brain;
}
