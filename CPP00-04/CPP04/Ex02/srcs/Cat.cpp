/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:03:44 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &value)
{
	*this = value;
}

Cat	&Cat::operator=(const Cat &value)
{
	type = value.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}
