/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 18:53:47 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
	try
	{
		if (gradeSign < 1 || gradeExec < 1)
			throw AForm::GradeTooHighException();
		if (gradeSign > 150 || gradeExec > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
}

AForm::~AForm()
{
}

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

void	AForm::signForm(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->gradeSign)
		{
			if (this->getSignState())
				throw AForm::FormAlreadySignedException();
			this->sign = true;
			this->signBy = bureaucrat.getName();
			std::cout << bureaucrat.getName() << " signs " << this->name << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << " for " << bureaucrat.getName() << std::endl;
	}
}

int	AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int	AForm::getGradeExec() const
{
	return (this->gradeExec);
}

void	AForm::setSignState(bool state)
{
	this->sign = state;
}

void	AForm::setSignBy(std::string const &name)
{
	this->signBy = name;
}
