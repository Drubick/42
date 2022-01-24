#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    std::string	input;
    	PhoneBook	phonebook;

    	while (true)
    	{
    		std::cout << "Waiting for command: ";
    		std::getline(std::cin, input);
    		if (input == "ADD")
    			phonebook.add();
    		else if (input == "SEARCH")
    			phonebook.search();
    		else if (input == "EXIT")
    			return (0);
    		else
    			std::cout << "Invalid input\n";
    	}
    	return (0);

}