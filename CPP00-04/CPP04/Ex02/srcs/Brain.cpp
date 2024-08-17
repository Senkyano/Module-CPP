/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:07:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/17 14:08:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("No Idea");
	return (ideas[i]);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	ideas[i] = idea;
}
