/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:35:45 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 12:00:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructeur
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &value) : AForm(value), target(value.target)
{
}

// Destructeur
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Operateur assign
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &value)
{
	AForm::operator=(value);
	return (*this);
}

// Member function
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor << " Try to executed presidential form\n";
	if (executor.getGrade() <= this->getGradeExec())
	{
		std::cout << executor << " executed " << this->getName() << std::endl;
		std::cout << this->target << " has been pardoned by founder" << std::endl;
		return ;
	}
	throw AForm::GradeTooLowException();
}