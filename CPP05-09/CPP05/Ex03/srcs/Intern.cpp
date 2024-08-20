/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:56:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 21:15:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string const& formName, std::string const& target)
{
	if (formName == "robotomy request")
		return (new RobotmyRequestForm(target));
	else if (formName == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else if (formName == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else
	{
		throw FormNotFoundException();
		return (NULL);
	}
}
