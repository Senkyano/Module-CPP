/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 14:40:34 by rihoy            ###   ########.fr       */
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
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		Bureaucrat	co_founder("Co-Founder", 25);
		Bureaucrat	direction("direction", 50);
		Bureaucrat	manager("Manager", 100);
		Bureaucrat	employee;

		Intern	bringcof;
		AForm	*form = bringcof.makeForm("president pardon", employee.getName());
		try {
			form->signForm(co_founder);
			form->execute(founder);
			form->execute(ceo);
		} catch (std::exception &e) {
			if (form)
				delete form;
			form = NULL;
			std::cerr << e.what() << std::endl;
		}
		if (form)
			delete form;

		AForm	*form2 = bringcof.makeForm("robotomy request", "Blender");
		try {
			form2->signForm(direction);
			form2->execute(co_founder);
		}
		catch (std::exception &e) {
			if (form2)
				delete form2;
			form2 = NULL;
			std::cerr << e.what() << std::endl;
		}
		if (form2)
			delete form2;
		AForm	*form3 = bringcof.makeForm("shrubbery request", "capital");
		try {	
			form3->signForm(manager);
			form3->execute(manager);
		} catch (std::exception &e) {
			if (form3)
				delete form3;
			form3 = NULL;
			std::cerr << e.what() << std::endl;
		}
		if (form3)
			delete form3;
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

		Intern	bringcof;
		AForm	*form1 = bringcof.makeForm("presidentpardon", employee.getName());
		AForm	*form21 = bringcof.makeForm("robotomy request", "Blender");
		AForm	*form31 = bringcof.makeForm("shrubbery request", "capital");

		form1->signForm(co_founder);
		form1->execute(founder);
		form1->execute(ceo);
		form21->signForm(direction);
		form21->execute(co_founder);
		form31->signForm(manager);
		form31->execute(manager);
	}
	catch (std::exception &e)	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}