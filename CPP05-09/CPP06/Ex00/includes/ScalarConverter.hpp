/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 15:11:29 by rihoy            ###   ########.fr       */
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
		~ScalarConverter();

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
