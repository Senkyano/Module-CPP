/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:35:45 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:26:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &value) : AForm(value)
{
	*this = value;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &value)
{
	(void)value;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		else if (executor.getGrade() < 1)
			throw AForm::GradeTooHighException();
		if (!this->getSignState())
			throw AForm::FormNotSignedException();
		std::cout << this->target << " has been pardoned by Founder" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " : " << e.what() << std::endl;
	}
}