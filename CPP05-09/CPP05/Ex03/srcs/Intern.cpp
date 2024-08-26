/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:56:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:26:25 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &value)
{
	*this = value;
}

Intern	&Intern::operator=(const Intern &value)
{
	(void)value;
	return (*this);
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
