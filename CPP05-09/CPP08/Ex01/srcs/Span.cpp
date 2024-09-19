/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:58:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 15:53:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdarg>
#include <cassert>
#include <limits>

// Span Constructor
Span::Span() : size(0)
{
}

Span::Span(unsigned int n) : size(n)
{
}

Span::Span(const Span &value) : size(value.size)
{
	*this = value;
}

Span	&Span::operator=(const Span &value)
{
	if (this != &value)
	{
		this->tab = value.tab;
		this->size = value.size;
	}
	return (*this);
}

// Span Destructor
Span::~Span()
{
}

// Span Member function
// 	The first parameter is the number of arguments we have
//	and the other's is the value

void	Span::addNumberRandom(int nbr, unsigned int many)
{
	try
	{
		std::srand(time(NULL) + nbr);
		for (unsigned int i = 0; i < many; ++i)
		{
			int random = rand() * (nbr) * (nbr * i);
			if (nbr < -2147483647 || nbr > 2147483647)
				throw Span::SpanOutException();
			if (this->tab.size() >= this->size)
				throw Span::SpanFullException();
			this->tab.push_back(random);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}

void	Span::addNumber(std::vector<int> other)
{
	try
	{
		if (this->tab.size() >= this->size)
			throw Span::SpanFullException();
		this->tab.insert(other.end(), other.begin(), other.end());
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}

void	Span::addNumber(Span &other)
{
	try
	{
		std::vector<int> tmp = other.tab;
		if (this->tab.size() >= this->size)
			throw Span::SpanFullException();
		this->tab.insert(this->tab.end(), tmp.begin(), tmp.end());
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}

void	Span::addNumber(int nbr)
{
	try
	{
		if (nbr < -2147483647 || nbr > 2147483647)
			throw Span::SpanOutException();
		if (this->tab.size() >= this->size)
			throw Span::SpanFullException();
		this->tab.push_back(nbr);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}

void	Span::addNumber1(int nbr_arg, ...)
{
	va_list	args;
	int	num = 0;

	try
	{
		va_start(args, nbr_arg);
		for (int i = 0; i < nbr_arg && (num = va_arg(args, int)) != 0; ++i)
		{
			if (num < -2147483647 || num > 2147483647)
				throw Span::SpanOutException();
			if (this->tab.size() >= this->size)
				throw Span::SpanFullException();
			this->tab.push_back(num);
		}
		va_end(args);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}

int		Span::shortestSpan()
{
	if (this->tab.size() <= 1)
		throw Span::SpanElementException();
	std::vector<int>	tmp = this->tab;
	std::sort(tmp.begin(), tmp.end());
	int	min;
	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); ++i)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int		Span::longestSpan()
{
	if (this->tab.size() <= 1)
		throw Span::SpanElementException();
	std::vector<int>	tmp = this->tab;
	std::sort(tmp.begin(), tmp.end());
	return (std::abs(tmp[tmp.size() - 1] - tmp[0]));
}

// Exception
const char *Span::SpanElementException::what() const throw()
{
	return ("Not enough of element");
}

const char *Span::SpanOccupedException::what() const throw()
{
	return ("Can't be there");
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Span Full");
}

const char *Span::SpanOutException::what() const throw()
{
	return ("Out of INT conception");
}
