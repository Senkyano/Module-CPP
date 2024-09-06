/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/06 23:38:25 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructeur
Form::Form() : name("Coffe ?"), gradeSign(150), gradeExec(150) 
{
	this->sign = false;
	this->signBy = "None as sign";
}

Form::Form(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
	this->signBy = "None as sign";
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &value) : name(value.name), gradeSign(value.gradeSign), gradeExec(value.gradeExec)
{
	this->sign = value.sign;
	this->signBy = value.signBy;
}

// Destructeur
Form::~Form()
{
}

// Operator Class
Form	&Form::operator=(const Form &value)
{
	if (this == &value)
		return (*this);
	*this = value;
	return (*this);
}

// Member functions 

//		Getter
std::string const	Form::getName() const
{
	return (this->name);
}

std::string const	&Form::getSignBy() const
{
	return (this->signBy);
}

bool	Form::getSignState() const
{
	return (this->sign);
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}

int	Form::getGradeExec() const
{
	return (this->gradeExec);
}
//		Setter
void	Form::beSign(Bureaucrat &bureaucrat)
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
}

// Exception
const char *Form::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high" RST);
}

const char *Form::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low" RST);
}

//	Operator <<
std::ostream	&operator<<(std::ostream &o, Form const &value)
{
	o << "Form : " << value.getName() << std::endl;
	o << "Sign by : " << value.getSignBy() << "; Sign state : " << value.getSignState() << std::endl;
	o << "Authorized Sign by grade : " << value.getGradeSign() << std::endl;
	o << "Authorized Exec by grade : " << value.getGradeExec() << std::endl;
	return (o);
}
