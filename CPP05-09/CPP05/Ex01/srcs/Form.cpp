/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/19 20:16:57 by rihoy            ###   ########.fr       */
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


