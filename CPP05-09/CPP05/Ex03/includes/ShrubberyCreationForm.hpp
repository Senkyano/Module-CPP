/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:12:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 01:11:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private : 
		std::string const	target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(const ShrubberyCreationForm &value);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &value);
		~ShrubberyCreationForm();

		std::string	getTarget() const;
		void		execute(Bureaucrat const &executor) const;

	class ShrubberyCreationFormException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

#endif
