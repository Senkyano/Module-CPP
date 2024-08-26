/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:23:00 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "main.hpp"

class	Bureaucrat
{
	private :
		std::string const	name;
		int				grade;

	public :
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &value);
		Bureaucrat	&operator=(const Bureaucrat &value);
		~Bureaucrat();

		std::string const	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return (RED "Grade is too high" RST);
			}
	};
	
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return (RED "Grade is too low" RST);
			}
	};
};

#endif
