/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 17:24:53 by rihoy            ###   ########.fr       */
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
		std::deque<t_data>	tmp;

		(void)bit;
		tmp = bit.getData();
		for (std::deque<t_data>::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			t_data	io = *it;
			std::cout << io.value_btc << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}