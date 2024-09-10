/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 14:38:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "BitcoinExchange.hpp"
#include <deque>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "To use : ./btc 'input.txt'\n";
		return (1);
	}
	std::string	input = std::string(argv[1]);
	if (input != "input.txt")
	{
		std::cout << "Wrong filename\n";
		return (1);
	}
	try
	{
		BitcoinExchange	bit;
		(void)bit;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}