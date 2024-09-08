/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:27:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/08 17:37:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructeur
RobotmyRequestForm::RobotmyRequestForm() : AForm("RobotmyRequestForm", 72, 45), target("none")
{
	srand(time(0));
}

RobotmyRequestForm::RobotmyRequestForm(std::string const target) : AForm("RobotmyRequestForm", 72, 45), target(target)
{
	srand(time(0));
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &value) : AForm(value), target(value.target)
{
}

// Desctructeur
RobotmyRequestForm::~RobotmyRequestForm()
{
}

// Operateur assign
RobotmyRequestForm	&RobotmyRequestForm::operator=(const RobotmyRequestForm &value)
{
	AForm::operator=(value);
	return (*this);
}

// Member function
void	RobotmyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor << " Try to executed robotomized form\n";
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << executor << " executed " << this->getName() << std::endl;
	std::cout << "Drilling ..." << std::endl;
	if (rand() % 2)
	{
		std::cout << RED << "Robotomized " << this->getName() << " has been failed\n";
		std::cout << "Robots calling " << executor.getName() << RST <<std::endl;
		return ;
	}
	std::cout << Y << this->getName() << " has been robotomized " << GR << "SUCCESFULLY" << RST << std::endl;
}
