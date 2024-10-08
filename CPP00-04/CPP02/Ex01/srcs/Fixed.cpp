/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:28:00 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/12 14:15:38 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::constValue = 8;

// Constructor

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->constValue;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->constValue));
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

// Assignation operator

Fixed &Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->value = value.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}

// Member functions

int 	Fixed::getRawBits(void) const
{
	return (this->value);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->constValue));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->constValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
