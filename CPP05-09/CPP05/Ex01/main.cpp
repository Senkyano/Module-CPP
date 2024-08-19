/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/19 18:49:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "main.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat("Rihoy", 1);
	bureaucrat.incrementGrade();
	std::cout << "Grade acutel : " << bureaucrat.getGrade() << std::endl;
	bureaucrat.decrementGrade();
	std::cout << "Grade acutel : " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(-60);
	std::cout << "Grade acutel : " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(150);
	std::cout << "Grade acutel : " << bureaucrat.getGrade() << std::endl;
	bureaucrat.decrementGrade();
	return (0);
}