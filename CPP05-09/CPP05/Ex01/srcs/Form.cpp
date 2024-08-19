/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 00:42:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
	try
	{
		if (gradeSign < 1 || gradeExec < 1)
			throw Form::GradeTooHighException();
		if (gradeSign > 150 || gradeExec > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
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
	try
	{
		if (bureaucrat.getGrade() <= this->gradeSign)
		{
			if (this->getSignState())
				throw Form::FormAlreadySignedException();
			this->sign = true;
			this->signBy = bureaucrat.getName();
			std::cout << bureaucrat.getName() << " signs " << this->name << std::endl;
		}
		else
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << " for " << bureaucrat.getName() << std::endl;
	}
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}

int	Form::getGradeExec() const
{
	return (this->gradeExec);
}