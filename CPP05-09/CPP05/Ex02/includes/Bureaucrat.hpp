/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 13:20:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "main.hpp"
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private :
		std::string const	name;
		int				grade;

	public :
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat();

		std::string const	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				executeForm(AForm const &form) const;
	
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
