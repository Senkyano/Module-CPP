/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 00:07:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructeur
AForm::AForm() : name("Coffe ?"), gradeSign(150), gradeExec(150) 
{
	this->sign = false;
	this->signBy = "None as sign";
}

AForm::AForm(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
	this->signBy = "None as sign";
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &value) : name(value.name), gradeSign(value.gradeSign), gradeExec(value.gradeExec)
{
	this->sign = value.sign;
	this->signBy = value.signBy;
}

// Destructeur
AForm::~AForm()
{
}

// Operator Class
AForm	&AForm::operator=(const AForm &value)
{
	if (this == &value)
		return (*this);
	*this = value;
	return (*this);
}

// Member functions 

//		Getter
std::string const	AForm::getName() const
{
	return (this->name);
}

std::string const	&AForm::getSignBy() const
{
	return (this->signBy);
}

bool	AForm::getSignState() const
{
	return (this->sign);
}

int	AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int	AForm::getGradeExec() const
{
	return (this->gradeExec);
}
//		Setter
void	AForm::beSign(Bureaucrat &bureaucrat)
{
	if (this->getGradeSign() > bureaucrat.getGrade())
	{
		if (this->getSignState())
		{
			std::cout << RED << bureaucrat.getName() << " couldn't sign " << this->getName();
			std::cout << " because " << this->getSignBy() << " already signed" << RST << std::endl;
			return ;
		}
		this->sign = true;
		this->signBy = bureaucrat.getName();
		std::cout << Y << bureaucrat.getName() << " signed " << this->name << RST << std::endl;
		return ;
	}
	throw AForm::GradeTooLowException();
}

// Exception
const char *AForm::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high" RST);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low" RST);
}

//	Operator <<
std::ostream	&operator<<(std::ostream &o, AForm const &value)
{
	o << "Form : " << value.getName() << std::endl;
	o << "Sign by : " << value.getSignBy() << "; Sign state : " << value.getSignState() << std::endl;
	o << "Authorized Sign by grade : " << value.getGradeSign() << std::endl;
	o << "Authorized Exec by grade : " << value.getGradeExec() << std::endl;
	return (o);
}
