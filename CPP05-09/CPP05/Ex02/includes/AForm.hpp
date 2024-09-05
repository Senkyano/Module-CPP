/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 11:56:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

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
		AForm();
		AForm(std::string const name, int gradeSign, int gradeExec);
		AForm(const AForm &value);
		AForm &operator=(const AForm &value);
		~AForm();

		std::string const	getName() const;
		std::string const	&getSignBy() const;
		void				signForm(Bureaucrat &bureaucrat);
		virtual	void		execute(Bureaucrat const &executor) const = 0;
		void				setSignState(bool state);
		void				setSignBy(std::string const &name);
		bool				getSignState() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class	FormAlreadySignedException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class	FormNotSignedException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

#endif