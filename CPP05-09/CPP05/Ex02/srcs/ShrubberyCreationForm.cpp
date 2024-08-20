/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:30:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 13:32:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class	ShrubberyCreationForm : public AForm
{
	private : 
		std::string const	target;

	public :
		ShrubberyCreationForm(std::string const target);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
