/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 21:26:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "main.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	founder("Founder", 5);
	Bureaucrat	co_founder("Co-Founder", 25);
	Bureaucrat	direction("direction", 50);
	Bureaucrat	manager("Manager", 100);
	Bureaucrat	employee("Employee", 150);

	AForm	*tmp;
	Intern	intern;
	
	tmp = NULL;
	try
	{
		tmp = intern.makeForm("robotomy request", ceo.getName());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (tmp)
	{
		tmp->signForm(ceo);
		tmp->execute(ceo);
		delete tmp;
		tmp = NULL;
	}
	try
	{
		tmp = intern.makeForm("presidential pardon", co_founder.getName());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (tmp)
	{
		tmp->signForm(employee);
		tmp->execute(employee);
		tmp->execute(founder);
		tmp->signForm(co_founder);
		tmp->execute(founder);
		delete tmp;
		tmp = NULL;
	}
	try
	{
		tmp = intern.makeForm("presidential pardon", employee.getName());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (tmp)
	{
		delete tmp;
		tmp = NULL;
	}
	try
	{
		tmp = intern.makeForm("qsd ol creation", direction.getName());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (tmp)
		delete tmp;
	return (0);
}