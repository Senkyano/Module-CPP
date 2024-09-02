/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/02 13:28:04 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(const Cat &value)
{
	this->type = value.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &value)
{
	this->type = value.type;
	return (*this);
}

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}
