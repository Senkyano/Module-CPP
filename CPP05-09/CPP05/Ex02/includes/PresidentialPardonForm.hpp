/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:24:40 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 01:12:18 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class	PresidentialPardonForm : public AForm
{
	private :
		std::string const	target;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm &value);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &value);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
