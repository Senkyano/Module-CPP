/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/13 09:36:17 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	constValue;

	public:
	// 4 constructors
		Fixed();
		Fixed(const Fixed &value);
		Fixed(const int value);
		Fixed(const float value);

	// 1 Destructor
		~Fixed();

	// 1 Assignation operator
		Fixed &operator=(const Fixed &value);

	// Member functions
		int 	getRawBits(void) const;
		void 	setRawBits(int const value);

		int		toInt(void) const;
		float	toFloat(void) const;

	// Comparison operators
		bool	operator>(const Fixed &value) const;
		bool	operator<(const Fixed &value) const;
		bool	operator>=(const Fixed &value) const;
		bool	operator<=(const Fixed &value) const;
		bool	operator==(const Fixed &value) const;
		bool	operator!=(const Fixed &value) const;

	// Arithmetic operators
		Fixed	operator+(const Fixed &value) const;
		Fixed	operator-(const Fixed &value) const;
		Fixed	operator*(const Fixed &value) const;
		Fixed	operator/(const Fixed &value) const;
	
	// Increment and decrement operators
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
	
	// Min and Max
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &value);

#endif