/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 16:02:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "./btc Could not open file\n" << RST;
		return (1);
	}
	std::string	input = std::string(argv[1]);
	try
	{
		BitcoinExchange	bit;
		bit.evolution_Wallet(input);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
