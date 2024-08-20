/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:54:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 21:07:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotmyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	public :
		Intern();
		~Intern();

		AForm*	makeForm(std::string const& formName, std::string const& target);

	class	FormNotFoundException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return ("Form not found");
			}
	};
};

#endif
