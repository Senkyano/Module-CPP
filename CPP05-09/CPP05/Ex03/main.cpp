/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 15:39:07 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "main.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testEx00(void);
// void	testEx01(void);
void	testEx02(void);

int	main(void)
{
	std::cout << PUR << "Test from Ex00" << RST << std::endl;
	testEx00();
	// std::cout << PUR << "\nTest from Ex01" << RST << std::endl;
	// // testEx01();
	// std::cout << PUR << "\nTest from Ex02" << RST << std::endl;
	// testEx02();
	std::cout << PUR << "\nTest from Ex03" << RST << std::endl;
	try {
		Bureaucrat	newArrival;
		Bureaucrat	ceo("Master", 1);
		Bureaucrat	founder("founder", 25);
		Bureaucrat	secret("secret", 72);
		Bureaucrat	manager("manager", 100);
		Intern		stage;
		AForm		*from1 = stage.makeForm("president pardon", "Random");
		AForm		*from2 = stage.makeForm("robotomy request", "Cellphone");
		AForm		*from3 = stage.makeForm("shrubbery request", "Random");
		
		std::cout << GR << "===== Show =====\n" << RST << std::endl;
		std::cout << newArrival << std::endl;
		std::cout << ceo << std::endl;
		std::cout << founder << std::endl;
		std::cout << secret << std::endl;
		std::cout << manager << std::endl;
		std::cout << std::endl;
		if (from1)
		{
			try {
				std::cout << "==== Test President Form ====\n";
				std::cout << GR << "===== Valid =====" << RST << std::endl;
				std::cout << *from1 << std::endl;
				ceo.executeForm(*from1);
				founder.signForm(*from1);
				ceo.signForm(*from1);
				ceo.executeForm(*from1);
				std::cout << "\n";
				std::cout << *from1;
				std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
				try {
					std::cout << "Lower grade try to sign\n";
					secret.signForm(*from1);
				} catch (std::exception &e) {
					std::cerr << e.what() << std::endl;
				}
				try {
					std::cout << "Lower grade try to exec\n";
					secret.executeForm(*from1);
				} catch (std::exception &e) {
					std::cerr << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			if (from1)
				delete from1;
		}
		if (from2)
		{
			try {
				std::cout << "\n==== Test Robotomized Form ====\n";
				std::cout << GR << "===== Valid =====" << RST << std::endl;
				std::cout << *from2 << std::endl;
				ceo.executeForm(*from2);
				founder.signForm(*from2);
				ceo.signForm(*from2);
				ceo.executeForm(*from2);
				std::cout << "\n";
				std::cout << *from2;
				std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
				try {
					std::cout << "Lower grade try to sign\n";
					manager.signForm(*from2);
				} catch (std::exception &e) {
					std::cerr << e.what() << std::endl;
				}
				try {
					std::cout << "Lower grade try to exec\n";
					secret.executeForm(*from2);
				} catch (std::exception &e) {
					std::cerr << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			if (from2)
				delete from2;
		}
		if (from3)
		{
			std::cout << "\n==== Test Shrubbery Form ====\n";
			std::cout << GR << "===== Valid =====" << RST << std::endl;
			std::cout << *from3 << std::endl;
			ceo.executeForm(*from3);
			founder.signForm(*from3);
			ceo.signForm(*from3);
			ceo.executeForm(*from3);
			std::cout << "\n";
			std::cout << *from3;
			std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
			try {
				std::cout << "Lower grade try to sign\n";
				newArrival.signForm(*from3);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			try {
				std::cout << "Lower grade try to exec\n";
				newArrival.executeForm(*from3);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			delete from3;
		}
		std::cout << "Test a form who isn't presidential; robotomized; shrubbery\n";
		AForm		*from6 = stage.makeForm("shrubberyrequest", "Random");
		if (from6)
		{
			std::cout << *from6 << std::endl;
			ceo.signForm(*from6);
			ceo.executeForm(*from6);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	testEx02(void)
{
	try {
		Bureaucrat	newArrival;
		Bureaucrat	ceo("Master", 1);
		Bureaucrat	founder("founder", 25);
		Bureaucrat	secret("secret", 72);
		Bureaucrat	manager("manager", 100);
		PresidentialPardonForm	presi("Random");
		ShrubberyCreationForm	shrub("schema");
		RobotmyRequestForm		robot("Sell Action");
		
		std::cout << GR << "===== Show =====\n" << RST << std::endl;
		std::cout << newArrival << std::endl;
		std::cout << ceo << std::endl;
		std::cout << founder << std::endl;
		std::cout << secret << std::endl;
		std::cout << manager << std::endl;
		std::cout << std::endl;
		std::cout << presi << std::endl;
		std::cout << robot << std::endl;
		std::cout << shrub << std::endl;
		std::cout << "==== Test President Form ====\n";
		std::cout << GR << "===== Valid =====" << RST << std::endl;
		ceo.executeForm(presi);
		founder.signForm(presi);
		ceo.signForm(presi);
		ceo.executeForm(presi);
		std::cout << "\n";
		std::cout << presi;
		std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
		try {
			std::cout << "Lower grade try to sign\n";
			secret.signForm(presi);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Lower grade try to exec\n";
			secret.executeForm(presi);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n==== Test Robotomized Form ====\n";
		std::cout << GR << "===== Valid =====" << RST << std::endl;
		ceo.executeForm(robot);
		founder.signForm(robot);
		ceo.signForm(robot);
		ceo.executeForm(robot);
		std::cout << "\n";
		std::cout << robot;
		std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
		try {
			std::cout << "Lower grade try to sign\n";
			manager.signForm(robot);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Lower grade try to exec\n";
			secret.executeForm(robot);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n==== Test Shrubbery Form ====\n";
		std::cout << GR << "===== Valid =====" << RST << std::endl;
		ceo.executeForm(shrub);
		founder.signForm(shrub);
		ceo.signForm(shrub);
		ceo.executeForm(shrub);
		std::cout << "\n";
		std::cout << shrub;
		std::cout << RED << "===== Invalid =====\n" << RST << std::endl;
		try {
			std::cout << "Lower grade try to sign\n";
			newArrival.signForm(shrub);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Lower grade try to exec\n";
			newArrival.executeForm(shrub);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RST << std::endl;
	}
	
}

// void	testEx01(void)
// {
// 	try {
// 		Bureaucrat	newArrival;
// 		Bureaucrat	ceo("Master", 1);
// 		AForm		promotions("Promotion", 50, 25);
		
// 		std::cout << GR << "===== Show Valid =====\n" << RST << std::endl;
// 		std::cout << newArrival << std::endl;
// 		std::cout << ceo << std::endl;
// 		std::cout << promotions << std::endl;
// 		try {
// 			ceo.signForm(promotions);
// 			std::cout << GR << promotions << std::endl;
// 			ceo.signForm(promotions);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 		std::cout << RED << "\n===== Showing Error =====\n" << RST << std::endl;
// 		std::cout << "Set a Form with higher value or lower value" << std::endl;
// 		try {
// 			std::cout << "Set value Sign = 0" << std::endl;
// 			AForm	fireCeo("fired ceo", 0, 1);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 		try {
// 			std::cout << "Set value Exec = 0" << std::endl;
// 			AForm	fireCeo("fired ceo", 1, 0);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 		try {
// 			std::cout << "Set value Sign = 151" << std::endl;
// 			AForm	fireCeo("fired ceo", 151, 1);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 		try {
// 			std::cout << "Set value Exec = 151" << std::endl;
// 			AForm	fireCeo("fired ceo", 1, 151);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 		std::cout << "\n";
// 		try {
// 			AForm	fireCeo("fired ceo", 1, 1);

// 			std::cout << fireCeo << std::endl;
// 			std::cout << "new employee want to fire ceo" << std::endl;
// 			std::cout << newArrival << std::endl;
// 			newArrival.signForm(fireCeo);
// 		} catch (std::exception &e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
	
// }

void	testEx00(void)
{
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
}
