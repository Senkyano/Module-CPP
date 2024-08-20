/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 00:41:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "main.hpp"

int	main(void)
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	founder("Founder", 5);
	Bureaucrat	co_founder("Co-Founder", 25);
	Bureaucrat	direction("direction", 50);
	Bureaucrat	manager("Manager", 100);
	Bureaucrat	employee("Employee", 150);

	Form		form("fire form", 75, 50);
	Form		form2("recruit form", 100, 75);
	Form		form3("Sell form", 25, 5);

	Form		form4("Error Form", 151, 0);
	Form		form5("Error Form2", 151, 2);
	Form		form6("Error Form3", -21, 151);

	form.signForm(employee);
	form.signForm(manager);
	form.signForm(direction);
	form.signForm(co_founder);
	form2.signForm(founder);
	form2.signForm(ceo);
	form3.signForm(direction);
	form3.signForm(co_founder);
	return (0);
}