/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/29 23:49:17 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	new Brain();
}

Dog::Dog(const Dog &value)
{
	*this = value;
	std::cout << "Dog copy constructor called" << std::endl;
	if (value.brain)
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
		if (this->brain)
			delete this->brain;
		if (value.brain)
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
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << type << " : woof woof" << std::endl;
}
