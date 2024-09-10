/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 12:41:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "BitcoinExchange.hpp"
#include <deque>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	l = std::atoi(argv[1]);
	std::cout << l % 4 << std::endl;
	return (0);
}