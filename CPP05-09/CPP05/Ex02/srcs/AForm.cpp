/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 12:03:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Coffee ?"), gradeSign(150), gradeExec(150)
{
}

AForm::AForm(std::string const name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	this->sign = false;
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

AForm	&AForm::operator=(const AForm &value)
{
	if (this == &value)
		return (*this);
	this->sign = value.sign;
	this->signBy = value.signBy;
	return (*this);
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

const char *AForm::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high" RST);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low" RST);
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return (RED "Form is already signed" RST);
}

const char *AForm::FormNotSignedException::what() const throw() {
	return (RED "Form is not signed" RST);
}
