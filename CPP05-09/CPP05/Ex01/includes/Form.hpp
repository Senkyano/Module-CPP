/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/19 19:59:45 by rihoy            ###   ########.fr       */
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
		std::string const	signBy;
		bool				sign;
		int const			gradeSign;
		int const			gradeExec;

	public :
		Form(std::string const name, int gradeSign, int gradeExec);
		~Form();

		std::string const	getName() const;
		std::string const	getSignBy() const;
		void				signFrom(Bureaucrat &bureaucrat);
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
};

#endif