/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:35:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 20:59:54 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "RPN.hpp"

int	main(int argc, const char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error\n" << RST;
		return (0);
	}
	RPN	rever_polish;

	rever_polish.calcul(std::string(argv[1]));
}
