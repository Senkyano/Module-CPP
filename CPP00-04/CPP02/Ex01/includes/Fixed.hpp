/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:27:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/12 14:13:48 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	constValue;
	public:
		Fixed();
		Fixed(const Fixed &value);
		Fixed(const int value);
		Fixed(const float value);

		~Fixed();

		Fixed &operator=(const Fixed &value);

		int 	getRawBits(void) const;
		void 	setRawBits(int const value);

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &value);

#endif
