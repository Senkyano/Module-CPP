/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 01:17:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CPP
# define AFORM_CPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private :
		std::string const	name;
		std::string			signBy;
		bool				sign;
		int const			gradeSign;
		int const			gradeExec;

	public :
	// Constructeur
		AForm();
		AForm(std::string const name, int gradeSign, int gradeExec);
		AForm(const AForm &value);
	
	// Descruteur
		~AForm();

	// Operator
		AForm &operator=(const AForm &value);

	// Member functions
		std::string const	getName() const;
		std::string const	&getSignBy() const;
		void				beSign(Bureaucrat &bureaucrat);
		bool				getSignState() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		virtual void		execute(Bureaucrat const &bureaucrat) const = 0;

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

std::ostream	&operator<<(std::ostream &o, AForm const &value);

#endif