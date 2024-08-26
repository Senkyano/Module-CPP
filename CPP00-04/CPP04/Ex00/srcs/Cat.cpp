/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:01:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
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
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}
