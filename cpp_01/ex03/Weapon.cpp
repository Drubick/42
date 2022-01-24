
#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type)
{
    this->type = type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void        Weapon::setType(std::string type){this->type = type;}
const std::string&	Weapon::getType( void )
{
	std::string& ref = this->type;
	return (ref);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */