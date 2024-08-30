/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 13:16:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &value)
{
	*this = value;
	std::cout << "Cat copy constructor called" << std::endl;
	if (value.getBrain())
	{
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, value.brain->getIdea(i));
	}
}

Dog	&Dog::operator=(const Dog &value)
{
	if (this != &value)
	{
		this->type = value.type;
		if (value.getBrain())
		{
			this->brain = new Brain();
			for (int i = 0; i < 100; i++)
				this->brain->setIdea(i, value.brain->getIdea(i));
		}
		else
			this->brain = NULL;
	}
	return (*this);
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << type << " : woof woof" << std::endl;
}
