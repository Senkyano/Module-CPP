/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 14:09:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "main.hpp"

bool	onlyDigits(std::string const str);
bool	isFloat(std::string const str);

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter	&operator=(const ScalarConverter &src);
		static void	convert(std::string const str);

	class	ScalarConversionException : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return ("impossible");
			}
	};
};

#endif
