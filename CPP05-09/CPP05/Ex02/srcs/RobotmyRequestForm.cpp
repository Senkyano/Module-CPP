/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:27:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/20 13:29:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>

class	RobotMyRequestForm : public AForm
{
	private :
		std::string const	target;

	public :
		RobotMyRequestForm(std::string const target);
		~RobotMyRequestForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
