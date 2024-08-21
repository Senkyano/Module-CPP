/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:39:25 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 14:57:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class Fixed
{
	private:
		int					value;
		static const int	constValue;

	public:
	// constructor
		Fixed();
		Fixed(const Fixed &value);
	// destructeur
		~Fixed();
	//surcharge operator
		Fixed &operator=(const Fixed &value);
	//getter
		int getRawBits(void) const;
	//setter
		void setRawBits(int const raw);
};

#endif