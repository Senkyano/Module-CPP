/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:12:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/19 16:46:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Canonique::Canonique() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Canonique::Canonique(const Canonique &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Canonique::~Canonique()
{
	std::cout << "Destructor called" << std::endl;
}

Canonique &Canonique::operator=(const Canonique &value)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = value.getRawBits();
	return (*this);
}

void	Canonique::setRawBits(int const raw)
{
	this->value = raw;
}

int	Canonique::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
