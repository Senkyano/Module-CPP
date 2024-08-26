/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:01:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(std::string type) : type(type)
{
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
}

void	Animal::makeSound() const
{
	std::cout << "that was an animal" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
