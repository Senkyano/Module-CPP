/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:46 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/12 14:46:38 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::constValue = 8;

// Constructor

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
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

// Comparison operators

bool	Fixed::operator>(const Fixed &value) const
{
	return (this->value > value.getRawBits());
}

bool	Fixed::operator<(const Fixed &value) const
{
	return (this->value < value.getRawBits());
}

bool	Fixed::operator>=(const Fixed &value) const
{
	return (this->value >= value.getRawBits());
}

bool	Fixed::operator<=(const Fixed &value) const
{
	return (this->value <= value.getRawBits());
}

bool	Fixed::operator==(const Fixed &value) const
{
	return (this->value == value.getRawBits());
}

bool	Fixed::operator!=(const Fixed &value) const
{
	return (this->value != value.getRawBits());
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed &value) const
{
	return (Fixed(this->toFloat() + value.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &value) const
{
	return (Fixed(this->toFloat() - value.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &value) const
{
	return (Fixed(this->toFloat() * value.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &value) const
{
	return (Fixed(this->toFloat() / value.toFloat()));
}

// Increment and decrement operators

// Assignation operator

Fixed &Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->value = value.getRawBits();
	return (*this);
}

// Non-member functions

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
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}