#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name)
{
	this->name = name;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

	void HumanB::setWeapon(Weapon weapon){this->weapon = weapon.getType();}
	void HumanB::attack(void)
{
	std::cout << this->name << "attacks with his " << this->weapon << "\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */