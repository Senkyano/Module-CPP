/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/13 14:22:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src) {}
	return (*this);
}

void	ScalarConverter::convert(std::string const str)
{
	double	f;
	bool	errorHandling;

	f = 0;
	errorHandling = false;
	if (str.length() == 1 && !isdigit(str[0]))
		f = static_cast<float>(str[0]);
	else if (str.length() != 1 && !onlyDigits(str)
		&& strcmp(str.c_str(), "-inff") && strcmp(str.c_str(), "inff")
			&& strcmp(str.c_str(), "nan") && strcmp(str.c_str(), "nanf") 
				&& strcmp(str.c_str(), "-inf") && strcmp(str.c_str(), "inf") && !isFloat(str))
		errorHandling = true;
	else
		f = strtod(str.c_str(), NULL);
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
		if (f == std::numeric_limits<float>::infinity() 
			|| f == -std::numeric_limits<float>::infinity() || std::isnan(f)
				|| f > 2147483647 || f < -2147483648)
			throw ScalarConversionException();
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	catch (ScalarConversionException &e)
	{
		std::cout << "int: " << RED << e.what() << RST << std::endl;
	}
	try
	{
		if (errorHandling || str.length() > 38)
			throw ScalarConversionException();
		if (f == std::numeric_limits<float>::infinity())
			std::cout << "float: " << "inff" << std::endl;
		else if (f == -std::numeric_limits<float>::infinity())
			std::cout << "float: " << "-inff" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	}
	catch (ScalarConversionException &e)
	{
		std::cout << "float: " << RED << e.what() << RST << std::endl;
	}
	try
	{
		if (errorHandling || str.length() > 308)
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

bool	onlyDigits(std::string const str)
{
	int		error = 0;
	size_t	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length())
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.' && !error)
			error = 1;
		else if (str[i] == '.' && error)
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(std::string const str)
{
	size_t	i;

	i = 0;
	while (i < str.length() - 1)
	{
		if (str[i] != '.' && !isdigit(str[i]))
			return (false);
		i++;
	}
	if (str[i] != 'f')
		return (false);
	return (true);
}
