/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:06:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 01:12:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class	RobotmyRequestForm : public AForm
{
	private :
		std::string const	target;

	public :
		RobotmyRequestForm();
		RobotmyRequestForm(std::string const target);
		RobotmyRequestForm(const RobotmyRequestForm &value);
		RobotmyRequestForm &operator=(const RobotmyRequestForm &value);
		~RobotmyRequestForm();

		void	execute(Bureaucrat const &executor) const;
	
	class RobotmyRequestFormException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	
};

#endif
