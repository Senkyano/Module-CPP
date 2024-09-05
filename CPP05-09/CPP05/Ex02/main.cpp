/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 14:06:13 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "main.hpp"

int	main(void)
{
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		Bureaucrat	co_founder("Co-Founder", 25);
		Bureaucrat	direction("direction", 50);
		Bureaucrat	manager("Manager", 100);
		Bureaucrat	employee;

		PresidentialPardonForm	form(employee.getName());
		RobotmyRequestForm		form2("Blender");
		ShrubberyCreationForm	form3("Capital");

		form.signForm(co_founder);
		form.execute(founder);
		form.execute(ceo);
		form2.signForm(direction);
		form2.execute(co_founder);
		form3.signForm(manager);
		form3.execute(manager);
	}
	catch (std::exception &e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		Bureaucrat	co_founder("Co-Founder", 25);
		Bureaucrat	direction("direction", 50);
		Bureaucrat	manager("Manager", 100);
		Bureaucrat	employee;

		PresidentialPardonForm	form(employee.getName());
		RobotmyRequestForm		form2("Blender");
		ShrubberyCreationForm	form3("Capital");

		form.signForm(employee);
		form.execute(employee);
		form.signForm(co_founder);
		form.execute(founder);
		form.execute(ceo);
		form2.signForm(direction);
		form2.execute(co_founder);
		form3.signForm(manager);
		form3.execute(manager);
	}
	catch (std::exception &e)	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}