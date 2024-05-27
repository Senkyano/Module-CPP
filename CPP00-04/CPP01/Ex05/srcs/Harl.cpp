/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:11:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/27 14:07:27 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	// std::cout << "Harl created" << std::endl;
}

Harl::~Harl()
{
	// std::cout << "Harl destroyed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "Harl : I love having extra bacon for my 7XL-Double-Cheese-";
	std::cout <<"triple-pickles-special-ketchup burger. I really do !";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Harl : ";
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger ! If you did,";
	std::cout << " I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Harl : I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming here for years and you just started working";
	std::cout << " here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Harl : This is unacceptable. I want to speak to the manager.";
	std::cout << std::endl;
}

/*

*/

void	Harl::complain(std::string level)
{
	void	(Harl::*complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levelHarl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i = 0;

	while (i < 4)
	{
		if (level == levelHarl[i])
		{
			(this->*complain[i])();
			break ;
		}
		i++;
	}
}
