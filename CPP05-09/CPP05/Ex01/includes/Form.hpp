/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/06 23:33:38 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private :
		std::string const	name;
		std::string			signBy;
		bool				sign;
		int const			gradeSign;
		int const			gradeExec;

	public :
	// Constructeur
		Form();
		Form(std::string const name, int gradeSign, int gradeExec);
		Form(const Form &value);
	
	// Descruteur
		~Form();

	// Operator
		Form &operator=(const Form &value);

	// Member functions
		std::string const	getName() const;
		std::string const	&getSignBy() const;
		void				beSign(Bureaucrat &bureaucrat);
		bool				getSignState() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

	// Exception
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &value);

#endif