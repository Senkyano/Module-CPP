/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:30:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 12:02:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructeur
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("none")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &value) : AForm(value), target(value.target)
{
}

// Destructeur
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Operateur assign
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &value)
{
	AForm::operator=(value);
	return (*this);
}

// Member function
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor << " Try to executed shrubbery form\n";
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << executor << " executed " << this->getName() << std::endl;
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

// Exception
const char *ShrubberyCreationForm::ShrubberyCreationFormException::what() const throw() {
	return (RED "ShrubberyCreationForm has failed" RST);
}
