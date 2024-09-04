/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 10:09:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &value) : Animal(value.type)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, value.brain->getIdea(i));
}

Dog	&Dog::operator=(const Dog &value)
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
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << type << " : woof woof" << std::endl;
}

std::string	Dog::getIdea(int i)
{
	return (this->brain->getIdea(i));
}

void	Dog::addIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}
