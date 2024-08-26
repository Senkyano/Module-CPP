/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:18:56 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:24:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &value) : name(value.name), grade(value.grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &value)
{
	if (this == &value)
		return (*this);
	this->grade = value.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int				Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
}

void		Bureaucrat::incrementGrade()
{
	this->grade--;
	try
	{
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
}

void		Bureaucrat::decrementGrade()
{
	try
	{
		this->grade++;
		if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->name << " : " << e.what() << std::endl;
	}
}
