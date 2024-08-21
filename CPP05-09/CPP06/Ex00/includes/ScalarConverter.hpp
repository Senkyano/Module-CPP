/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 14:55:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "main.hpp"

bool	onlyDigits(std::string const str);

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();

		static void	convert(std::string const str)
		{
			float	f;
			bool	errorHandling;

			errorHandling = false;
			if (str.length() == 1 && !isdigit(str[0]))
				f = static_cast<float>(str[0]);
			else if (str.length() != 1 && !onlyDigits(str)
				&& strcmp(str.c_str(), "-inff") && strcmp(str.c_str(), "inff")
					&& strcmp(str.c_str(), "nan"))
				errorHandling = true;
			else
				f = strtof(str.c_str(), NULL);
			try
			{
				if (f < 32 || f > 126 || std::isnan(f))
					throw ScalarConversionException();
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			}
			catch (ScalarConversionException &e)
			{
				std::cout << "char: " << RED << e.what() << RST << std::endl;
			}
			try
			{
				if (errorHandling)
					throw ScalarConversionException();
				if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() || std::isnan(f))
					throw ScalarConversionException();
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			}
			catch (ScalarConversionException &e)
			{
				std::cout << "int: " << RED << e.what() << RST << std::endl;
			}
			try
			{
				if (errorHandling)
					throw ScalarConversionException();
				if (f == std::numeric_limits<float>::infinity())
					std::cout << "float: " << "inff" << std::endl;
				else if (f == -std::numeric_limits<float>::infinity())
					std::cout << "float: " << "-inff" << std::endl;
				else
					std::cout << "float: " << f << "f" << std::endl;
			}
			catch (ScalarConversionException &e)
			{
				std::cout << "float: " << RED << e.what() << RST << std::endl;
			}
			try
			{
				if (errorHandling)
					throw ScalarConversionException();
				if (f == std::numeric_limits<double>::infinity())
					std::cout << "double: " << "inf" << std::endl;
				else if (f == -std::numeric_limits<double>::infinity())
					std::cout << "double: " << "-inf" << std::endl;
				else
					std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			catch (ScalarConversionException &e)
			{
				std::cout << "double: " << RED << e.what() << RST << std::endl;
			}
		}

	class	ScalarConversionException : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return ("impossible");
			}
	};
};



#endif
