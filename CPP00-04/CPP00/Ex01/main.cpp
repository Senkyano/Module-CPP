/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:39:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/17 12:53:58 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "phonebook.hpp"
#include "contact.hpp"

void	print_menu(void);

int	main(int argc, char **argv)
{
	std::string	input;
	Phonebook	Phone;

	(void)argv;
	if (argc != 1)
	{
		std::cout << RED << "Can't take any information at start" << RST << std::endl;
		return (1);
	}
	while (1)
	{
		print_menu();
		while (1)
		{
			std::cout << PUR << "	╚> " << RST;
			std::getline(std::cin, input);
			if (input.empty() && !std::cin.eof())
			{
				std::cout << RED << "	   Please enter a command" << RST << std::endl;
			}
			else if (std::cin.eof() || std::cin.fail())
			{
				return (0);
			}
			if (strcmp(input.c_str(), "EXIT") == 0)
				return (0);
			else if (strcmp(input.c_str(), "ADD") == 0)
			{
				Phone.addContact();
				break ;
			}
			else if (strcmp(input.c_str(), "SEARCH") == 0)
			{
				Phone.displayContacts();
				break ;
			}
			else
			{
				std::cout << RED << "	   Invalid command" << RST << std::endl;
			}
		}
	}
	return (0);
}

void	print_menu(void)
{
	std::cout << "#================ "<< GR << "MENU" << RST << " ================#" << std::endl;
	std::cout << "| " << GR << "ADD" << BLU << "    . Create a new contact" << RST << "        |" << std::endl;
	std::cout << "| " << GR << "SEARCH"<< BLU << " . Search a contact"<< RST << "            |" << std::endl;
	std::cout << "| " << GR << "EXIT" << BLU << "   . Exit" << RST << "                        |" << std::endl;
	std::cout << "#======================================#" << std::endl;
}
