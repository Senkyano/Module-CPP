/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 11:48:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Coffe ?"), gradeSign(150), gradeExec(150) 
{
}

Form::Form(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
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

Form	&Form::operator=(const Form &value)
{
	if (this == &value)
		return (*this);
	this->sign = value.sign;
	this->signBy = value.signBy;
	return (*this);
}

Form::~Form()
{
}

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

void	Form::signForm(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeSign)
	{
		if (this->getSignState())
			throw Form::FormAlreadySignedException();
		this->sign = true;
		this->signBy = bureaucrat.getName();
		std::cout << Y << bureaucrat.getName() << " signs " << this->name << RST << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

void	Form::execForm(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeExec)
		std::cout << GR <<bureaucrat.getName() << " exec " << this->name  << RST << std::endl;
	else
		throw Form::GradeTooLowException();
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}

int	Form::getGradeExec() const
{
	return (this->gradeExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RST);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RST);
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return (RED "Form is already signed" RST);
}
