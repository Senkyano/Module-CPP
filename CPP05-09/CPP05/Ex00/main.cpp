/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 11:35:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "main.hpp"

int	main()
{
	try {
		Bureaucrat	bur("Rihoy", 1);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.decrementGrade();
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.setGrade(-60);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.setGrade(150);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	bur("Rihoy", 1);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.setGrade(-60);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.setGrade(150);
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	bur;
		std::cout << "Grade acutel : " << bur.getGrade() << std::endl;
		bur.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}