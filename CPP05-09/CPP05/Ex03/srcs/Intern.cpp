/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:56:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 15:38:25 by rihoy            ###   ########.fr       */
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
	if (this == &value)
		return (*this);
	*this = value;
	return (*this);
}

Intern::~Intern()
{
}

AForm	*makePresident(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRoboto(std::string const target)
{
	return (new RobotmyRequestForm(target));
}

AForm	*makeShrubbery(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string	nameForm[3] = {"robotomy request", "president pardon", "shrubbery request"};
	AForm	*(*f[3])(std::string) = {&makeRoboto, &makePresident, &makeShrubbery};

	for (int i = 0; i < 3; ++i)
	{
		if (nameForm[i] == formName)
			return ((*f[i])(target));
	}
	throw	Intern::FormNotFoundException();
	return (NULL);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}