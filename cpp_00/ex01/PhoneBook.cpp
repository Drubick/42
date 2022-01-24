#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook()
{
    contacts_lenght = 0;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::add(void)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    if (this->contacts_lenght == 8)
        std::cout << "Maximum amount of contacts archived, the last contact will be overwritted\n";
    std::cout << "\nPleas introduce the data \n";
    std::cout << "First_name: ";
    std::getline(std::cin, first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone_number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Darkest_secret: ";
    std::getline(std::cin, darkest_secret);

    Contact newContact(first_name, last_name, nickname, phone_number, darkest_secret);
    int i = this->contacts_lenght < 8 ? this->contacts_lenght : 7;

    while(i > 0)
    {  
        //std::cout << i << "\n";
        //voy poniendo los contactos a final del array
        this->contacts[i] = this->contacts[i-1];
        i--;
    }
    this->contacts[0] = newContact;
    if(this->contacts_lenght < 8)
        this->contacts_lenght++;
    std::cout << "\n Contact completed\n";
}

void	PhoneBook::print_trimmed_field(std::string field)
{
	if (field.length() <= 10)
	{
		std::cout << std::setw(10) << std::right;
		std::cout << field;
	}
	else
	{
		for (short i = 0; i < 9; i++)
			std::cout << field[i];
		std::cout << '.';
	}
	std::cout << "|";
}

void    PhoneBook::display_table_c(void)
{
    Contact current_contact;
    std::cout <<"\nList of saved contacts.\n     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
    for (int i  = 0; i < this->contacts_lenght; i++)
    {
        current_contact = this->contacts[i];
        std::cout << std::right << std::setw(10);
        std::cout << i << "|";
        this->print_trimmed_field(current_contact.first_name);
        this->print_trimmed_field(current_contact.last_name);
        this->print_trimmed_field(current_contact.nickname);
        std::cout << "\n";
    }
}

void	PhoneBook::search(void)
{
	if (this->contacts_lenght == 0)
	{
		std::cout << "\nThere are no contacts added\n";
		return ;
	}

	this->display_table_c();
	int			index;
	std::string	input;
	while (true) {
		std::cout << "\nEnter the index of the desired contact: ";
		std::getline(std::cin, input);
		try {
			index = std::stoi(input, NULL, 10);
			if (index >= 0 && index < this->contacts_lenght)
				break ;
			else
				std::cout << "Error: Index must be between 0 and "
				<< this->contacts_lenght - 1 << " (both included)\n";
		}
		catch (std::invalid_argument) { std::cout << "Error: Non numeric argument\n"; }
		catch (std::out_of_range) { std::cout << "Error: Index out of range of int\n"; }
	}
	this->contacts[index].display_contact_information();
}