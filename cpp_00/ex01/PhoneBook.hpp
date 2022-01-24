#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{

	public:
		Contact contacts[8];
		int contacts_lenght;
		PhoneBook();
		~PhoneBook();
		void add(void);
		void search(void);


	private:
		void	display_table_c(void);
		void	print_trimmed_field(std::string field);

};

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i );

#endif /* ******************************************************* PHONEBOOK_H */