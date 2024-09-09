/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:50:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/09 20:43:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	tmp(10000);
	Span	tp(5);

	try
	{
		tmp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		tmp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	for (int index = -4647; index < 5353; ++index)
	{
		if (index == 0)
			tmp.addNumber(200000);
		else
			tmp.addNumber(index * index);
	}
	tp.addNumber(-23);
	tp.addNumber(100);
	tp.addNumber(230);
	tp.addNumber(254);
	tp.addNumber(1);
	try
	{
		std::cout << GR << "Longest tp : " << tp.longestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Shortest tp : " << tp.shortestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Longest tmp : " << tmp.longestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Shortest tmp : " << tmp.shortestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
}
