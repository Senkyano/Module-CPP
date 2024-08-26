/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:23:24 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Form
{
	private :
		std::string const	name;
		std::string			signBy;
		bool				sign;
		int const			gradeSign;
		int const			gradeExec;

	public :
		Form(std::string const name, int gradeSign, int gradeExec);
		Form(const Form &value);
		Form &operator=(const Form &value);
		~Form();

		std::string const	getName() const;
		std::string const	&getSignBy() const;
		void				signForm(Bureaucrat &bureaucrat);
		bool				getSignState() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return (RED "Grade is too high" RST);
			}
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return (RED "Grade is too low" RST);
			}
	};

	class	FormAlreadySignedException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return (RED "Form is already signed" RST);
			}
	};
};

#endif