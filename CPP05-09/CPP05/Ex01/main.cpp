/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 11:49:27 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "main.hpp"

int	main(void)
{
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		
		Form	form1("Sell Action", 6, 2);
		
		form1.signForm(founder);
		form1.signForm(ceo);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		
		Form	form1("Sell Action", 6, 2);
		
		form1.signForm(founder);
		form1.execForm(ceo);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	founder("Founder", 5);
		Bureaucrat	employee;
		
		Form	form1("Sell Action", 6, 2);
		
		form1.signForm(founder);
		std::cout << employee.getName() << " : ";
		form1.execForm(employee);
		form1.execForm(ceo);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}