/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:50:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 15:48:54 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	tmp(10000);
	Span	tmp2(20000);
	Span	tp(6);
	// std::vector<int> lol = {1, 5, 9, 50, 88888888};

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
	for (int index = -14647; index < 5348; ++index)
	{
		if (index == 0)
			tmp2.addNumber(200000);
		else
		{
			if (index * index * index > 2147483647)
				tmp2.addNumber(index);
			else if ((double)(index * index * index) < -2147483648)
				tmp2.addNumber(index);
			else
				tmp2.addNumber(index * index);
		}
	}
	Span tp2(5000);
	tp.addNumber1(2, 48, 20);
	tp.addNumber(100);
	tp.addNumber(230);
	tp.addNumber(99);
	tp.addNumberRandom(125, 2);
	tp2.addNumberRandom(9991, 5000);
	tmp2.addNumber(tp);
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
	try
	{
		std::cout << GR << "Longest tmp2 : " << tmp2.longestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Shortest tmp2 : " << tmp2.shortestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Longest tp2 : " << tp2.longestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << GR << "Shortest tp2 : " << tp2.shortestSpan() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
}
