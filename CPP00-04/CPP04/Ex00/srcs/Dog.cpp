/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/02 13:28:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &value)
{
	this->type = value.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &value)
{
	this->type = value.type;
	return (*this);
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << type << " : woof woof" << std::endl;
}
