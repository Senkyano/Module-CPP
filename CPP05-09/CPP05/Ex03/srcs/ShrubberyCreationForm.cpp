/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:30:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:26:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &value) : AForm(value)
{
	*this = value;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &value)
{
	(void)value;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		else if (executor.getGrade() < 1)
			throw AForm::GradeTooHighException();
		if (!this->getSignState())
			throw AForm::FormNotSignedException();
		
		std::string 	newFile = this->getTarget() + "_shrubbery";
		std::ofstream 	file;

		file.open(newFile.c_str());
		if (!file.is_open())
			throw ShrubberyCreationForm::ShrubberyCreationFormException();
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "====================" << std::endl;
		file << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
