/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/29 23:47:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
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
		if (this->brain)
			delete this->brain;
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
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}

std::string	Cat::getIdea(int i)
{
	return (this->brain->getIdea(i));
}

void		Cat::addIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}
