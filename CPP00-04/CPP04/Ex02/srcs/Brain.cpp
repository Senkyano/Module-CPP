/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:07:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 12:19:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &value)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = value;
}

Brain	&Brain::operator=(const Brain &value)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = value.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("No Idea");
	if (ideas[i].empty())
		return ("No Idea");
	return (ideas[i]);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	ideas[i] = idea;
}
