/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:01:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &value)
{
	*this = value;
}

Dog	&Dog::operator=(const Dog &value)
{
	type = value.type;
	return (*this);
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << type << " : woof woof" << std::endl;
}
