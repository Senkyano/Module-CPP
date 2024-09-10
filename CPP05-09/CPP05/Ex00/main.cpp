/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 13:23:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "main.hpp"

int	main() {
	try {
		Bureaucrat	newArrival;
		Bureaucrat	ceo("Master", 1);

		std::cout << "===== Demo constructor & operator assign =====\n" << std::endl;
		Bureaucrat	other(newArrival);

		std::cout << "other constructor by copy with 'newArrival' \n";
		std::cout << other << std::endl;
		other = ceo;
		std::cout << "other assign as ceo\n";
		std::cout << other << std::endl;
		
		std::cout << GR << "\n===== Show Valid =====\nMember of compagnie\n" << RST << std::endl;
		std::cout << newArrival << std::endl;
		std::cout << ceo << std::endl;
		std::cout << GR << "Showing increment and decrementation function" << RST << std::endl;
		try {
			ceo.decrementGrade();
			newArrival.incrementGrade();
			std::cout << newArrival << std::endl;
			std::cout << ceo << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << RED << "\n=====Showing Error=====\n" << RST << std::endl;
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
		std::cout << "Set a Bureaucrat with higher value or lower value" << std::endl;
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
	return (0);
}