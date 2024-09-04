/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:59:23 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 10:01:23 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &value)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = value;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &value)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->type = value.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {};

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}