/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:29:17 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/13 18:09:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// Constructor and Destructor

Phonebook::Phonebook(void)
{
	this->lastAdded = 0;
}

Phonebook::~Phonebook(void)
{
	
}

// Set Contact

void	Phonebook::addContact(void)
{
	std::string	line;

	if (this->lastAdded == 8)
		this->lastAdded = 0;
	while (1)
	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, line);
		if (line.empty() && !std::cin.eof())
			std::cout << RED << "First name cannot be empty." << RST << std::endl;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else
		{
			this->contacts[lastAdded].setFirstName(line);
			break;
		}
	}
	while (1)
	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, line);
		if (line.empty() && !std::cin.eof())
			std::cout << RED << "Last name cannot be empty." << RST << std::endl;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else
		{
			this->contacts[lastAdded].setLastName(line);
			break;
		}
	}
	while (1)
	{
		std::cout << "Enter nickname : ";
		std::getline(std::cin, line);
		if (line.empty() && !std::cin.eof())
			std::cout << RED << "Nickname cannot be empty." << RST << std::endl;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else
		{
			this->contacts[lastAdded].setNickname(line);
			break;
		}
	}
	while (1)
	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, line);
		if (line.empty() && !std::cin.eof())
			std::cout << RED << "Phone number cannot be empty." << RST << std::endl;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else
		{
			this->contacts[lastAdded].setPhoneNumber(line);
			break;
		}
	}
	while (1)
	{
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, line);
		if (line.empty() && !std::cin.eof())
			std::cout << RED << "Darkest secret cannot be empty." << RST << std::endl;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else
		{
			this->contacts[lastAdded].setDarkestSecret(line);
			break;
		}
	}
	this->lastAdded++;
}

// Get Contact

void	Phonebook::getContact(int index)
{
	std::cout << " First name : " << contacts[index].getFirstName() << std::endl;
	std::cout << " Last name : " << contacts[index].getLastName() << std::endl;
	std::cout << " Nickname : " << contacts[index].getNickname() << std::endl;
	std::cout << " Phone number : " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << " Darkest secret : " << contacts[index].getDarkestSecret() << std::endl;
}

void	Phonebook::displayContacts(void)
{
	std::string	str;
	int			i;

	i = -1;
	std::cout << "		#===================================================#" << std::endl;
	std::cout << "		|    Index   | First Name | Last Name  | Nickname   |" << std::endl;
	while (++i < 8)
	{
		std::cout << "		#---------------------------------------------------#" << std::endl;
		std::cout << "		|     " << i + 1 << "      | ";
		getInfo(contacts[i].getFirstName());
		getInfo(contacts[i].getLastName());
		getInfo(contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "		#====================================================#" << std::endl;
	std::cout << "		|                       " << GR <<"EXIT" << RST << "                        |" << std::endl;
	std::cout << "		#====================================================#" << std::endl;
	while (1)
	{
		std::cout << PUR << "╚> " << RST;
		std::getline(std::cin, str);
		if (strcmp(str.c_str(), "EXIT") == 0)
			break ;
		else if (std::cin.eof() || std::cin.fail())
			return ;
		else if (str[0] >= '1' && str[0] <= '8' && str[1] == '\0')
		{
			i = str[0] - '0';
			if (i > 0 && i <= 8)
				getContact(i - 1);
		}
		else
			std::cout << RED << "Invalid index" << RST << std::endl;
	}
}

void	Phonebook::getInfo(std::string str)
{
	int			i;
	int			right;
	int			length;

	length = str.length();
	right = 10 - length;
	if (right > 0)
	{
		while (right-- > 0)
			std::cout << " ";
		right = length - 10;
	}
	else
		right = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		std::cout << str[i];
		if (i + right == 8 && length > 10)
		{
			std::cout << ".";
			break ;
		}
	}
	std::cout << " | ";
}
