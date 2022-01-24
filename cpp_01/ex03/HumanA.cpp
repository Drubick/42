#include "HumanA.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->weapon = weapon.getType();
	this->name = name;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack(void)
{
	std::cout << this->name << "attacks with his " << weapon.getType() << "\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */