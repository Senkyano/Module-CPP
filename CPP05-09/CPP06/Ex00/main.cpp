/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 13:45:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "main.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter	scalarConverter;

	if (argc != 2)
	{
		std::cout << RED << "Error Usage : " << RST;
		std::cout << "./convert [value]" << std::endl;
		return (1);
	}
	// std::string str = argv[1];
	scalarConverter.convert(argv[1]);
	// float f = std::wcstof(str.c_str(), NULL);
	// float f = strtof(str.c_str(), NULL);
	// double d = f;
	// int i = f;
	// if (f == std::numeric_limits<float>::infinity())
	// 	std::cout << "float: " << f << std::endl;
	// std::cout << "double: " << d << std::endl;
	// std::cout << "int: " << i << std::endl;
}
