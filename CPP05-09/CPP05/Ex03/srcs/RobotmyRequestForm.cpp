/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:27:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 13:51:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(std::string const target) : AForm("RobotmyRequestForm", 72, 45), target(target)
{
	srand(time(0));
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &value) : AForm(value), target(value.target)
{
}

RobotmyRequestForm	&RobotmyRequestForm::operator=(const RobotmyRequestForm &value)
{
	AForm::operator=(value);
	return (*this);
}

RobotmyRequestForm::~RobotmyRequestForm()
{
}

void	RobotmyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	if (!this->getSignState())
		throw AForm::FormNotSignedException();
	if (rand() % 2)
		throw RobotmyRequestForm::RobotmyRequestFormException();
	std::cout << Y << this->target << " has been robotomized " << GR << "SUCCESFULLY" << RST << std::endl;
}

const char *RobotmyRequestForm::RobotmyRequestFormException::what() const throw() {
	return (RED "RobotmyRequestForm has failed" RST);
}
