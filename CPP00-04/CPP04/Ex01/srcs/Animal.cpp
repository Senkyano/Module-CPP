/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/17 14:55:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->brain = new Brain();
}

Animal::Animal(std::string type) : type(type)
{
	this->brain = new Brain();
	std::cout << "Animal type constructor called" << std::endl;
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
