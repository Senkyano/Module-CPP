/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:27:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 20:35:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(std::string const target) : AForm("RobotmyRequestForm", 72, 45), target(target)
{
	srand(time(0));
}

RobotmyRequestForm::~RobotmyRequestForm()
{
}

void	RobotmyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		else if (executor.getGrade() < 1)
			throw AForm::GradeTooHighException();
		if (!this->getSignState())
			throw AForm::FormNotSignedException();
		if (rand() % 2)
			throw RobotmyRequestForm::RobotmyRequestFormException();
		std::cout << "RobotmyRequestForm has been executed " << GR << "SUCCESFULLY" << RST << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " : " << e.what() << std::endl;
	}
}