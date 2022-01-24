#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

	public:

		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon weapon);
		void attack(void);

	private:

    std::string weapon;
	std::string name;

};

#endif