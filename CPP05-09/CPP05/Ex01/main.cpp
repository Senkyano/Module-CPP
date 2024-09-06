/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/06 23:32:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "main.hpp"

void	testEx00(void);

int	main(void)
{
	std::cout << PUR << "Test from Ex00" << RST << std::endl;
	testEx00();
	std::cout << PUR << "\nTest from Ex01" << RST << std::endl;
	try {
		Bureaucrat	newArrival;
		Bureaucrat	ceo("Master", 1);
		Form		promotions("Promotion", 50, 25);
		
		std::cout << GR << "===== Show Valid =====\n" << RST << std::endl;
		std::cout << newArrival << std::endl;
		std::cout << ceo << std::endl;
		std::cout << promotions << std::endl;
		try {
			ceo.signForm(promotions);
			std::cout << GR << promotions << std::endl;
			ceo.signForm(promotions);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << RED << "\n===== Showing Error =====\n" << RST << std::endl;
		std::cout << "Set a Form with higher value or lower value" << std::endl;
		try {
			std::cout << "Set value Sign = 0" << std::endl;
			Form	fireCeo("fired ceo", 0, 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Set value Exec = 0" << std::endl;
			Form	fireCeo("fired ceo", 1, 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Set value Sign = 151" << std::endl;
			Form	fireCeo("fired ceo", 151, 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Set value Exec = 151" << std::endl;
			Form	fireCeo("fired ceo", 1, 151);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n";
		try {
			Form	fireCeo("fired ceo", 1, 1);

			std::cout << fireCeo << std::endl;
			std::cout << "new employee want to fire ceo" << std::endl;
			std::cout << newArrival << std::endl;
			newArrival.signForm(fireCeo);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	testEx00(void)
{
	try {
		Bureaucrat	newArrival;
		Bureaucrat	ceo("Master", 1);
		
		std::cout << GR << "===== Show Valid =====\nMember of compagnie\n" << RST << std::endl;
		std::cout << newArrival << std::endl;
		std::cout << ceo << std::endl;
		std::cout << GR << "\nShowing increment and decrementation function\n" << RST << std::endl;
		try {
			ceo.decrementGrade();
			newArrival.incrementGrade();
			std::cout << newArrival << std::endl;
			std::cout << ceo << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << RED << "\n===== Showing Error =====\n" << RST << std::endl;
		try {
			std::cout << ceo << std::endl;
			std::cout << "Increment 2 time ceo" << std::endl;
			ceo.incrementGrade();
			ceo.incrementGrade();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << newArrival << std::endl;
			std::cout << "Decrement 2 time newArrival" << std::endl;
			newArrival.decrementGrade();
			newArrival.decrementGrade();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nSet a Bureaucrat with higher value or lower value" << std::endl;
		try {
			std::cout << "\nSet a bureaucrat above 1" << std::endl;
			Bureaucrat	bouddha("Divinity", 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Set a bureaucrat below 150" << std::endl;
			Bureaucrat	citizen("Random", 151);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
