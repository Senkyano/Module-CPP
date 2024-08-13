/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:46 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/13 09:40:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::constValue = 8;

// Constructor

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->constValue;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->constValue));
}

// Destructor

Fixed::~Fixed()
{

}

// Copy constructor

Fixed::Fixed(const Fixed &value)
{
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

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// Min and Max

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// Assignation operator

Fixed &Fixed::operator=(const Fixed &value)
{
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