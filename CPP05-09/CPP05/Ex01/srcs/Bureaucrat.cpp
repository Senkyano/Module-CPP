/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:18:56 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/11 14:35:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructeur
Bureaucrat::Bureaucrat() : name("Employee"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &value) : name(value.name), grade(value.grade)
{
}

// Destructeur
Bureaucrat::~Bureaucrat()
{
}

// Operator function
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &value)
{
	if (this == &value)
		return (*this);
	this->grade = value.grade;
	return (*this);
}

//	Member Function

//		Getter
std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int				Bureaucrat::getGrade() const
{
	return (this->grade);
}

//		Setter
void		Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void		Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void		Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::signForm(Form &value)
{
	if (value.getGradeSign() < this->getGrade())
		throw Bureaucrat::GradeTooLowException();
	value.beSign(*this);
}

// Exception
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RST);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RST);
}

//		Operator <<
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &value)
{
	o << value.getName() << ", bureaucrat grade " << value.getGrade();
	return (o);
}
