/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 20:32:57 by rihoy            ###   ########.fr       */
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
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	founder("Founder", 5);
	Bureaucrat	co_founder("Co-Founder", 25);
	Bureaucrat	direction("direction", 50);
	Bureaucrat	manager("Manager", 100);
	Bureaucrat	employee("Employee", 150);

	PresidentialPardonForm	form("PresidentialPardonForm");
	RobotmyRequestForm		form2("RobotmyRequestForm");
	ShrubberyCreationForm	form3("ShrubberyCreationForm");

	form.signForm(employee);
	form.execute(employee);
	form.signForm(co_founder);
	form.execute(founder);
	form.execute(ceo);
	form2.signForm(direction);
	form2.execute(co_founder);
	form3.signForm(manager);
	form3.execute(manager);
	return (0);
}