/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/29 10:54:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &value)
{
	*this = value;
}

Animal	&Animal::operator=(const Animal &value)
{
	if (this == &value)
		return (*this);
	type = value.type;
	return (*this);
}

Animal::~Animal()
{
	delete this->brain;
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "that was an animal" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::setIdeaAnimal(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string	Animal::getIdeaAnimal(int i)
{
	return (brain->getIdea(i));
}
