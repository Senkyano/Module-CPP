/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 13:16:00 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(const Cat &value)
{
	*this = value;
	std::cout << "Cat copy constructor called" << std::endl;
	if (value.getBrain())
	{
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, value.brain->getIdea(i));
	}
	std::cout << "act cat : " << &value << std::endl;
	std::cout << "new cat : " << this << std::endl;
	std::cout << "act Brain : " << &value.brain << std::endl;
	std::cout << "new Brain : " << &this->brain << std::endl;
}

Cat	&Cat::operator=(const Cat &value)
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

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}
