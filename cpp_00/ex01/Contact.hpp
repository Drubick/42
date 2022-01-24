#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
#include "Contact.hpp"

class Contact
{

	public:	
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string darkest_secret;

		Contact(void);
		Contact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone, std::string secret);
		~Contact();
		void	display_contact_information(void);
};



#endif /* ********************************************************* CONTACT_H */