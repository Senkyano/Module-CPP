/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:29:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 15:01:22 by rihoy            ###   ########.fr       */
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
	scalarConverter.convert(argv[1]);
}
