/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:58:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/09 20:44:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
void	Span::addNumber(int nbr)
{
	try
	{
		if (nbr < -2147483647 || nbr > 2147483647)
			throw Span::SpanOutException();
		if (this->tab.size() >= this->size)
			throw Span::SpanFullException();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
	this->tab.push_back(nbr);
}

int		Span::shortestSpan()
{
	if (this->tab.size() <= 1)
		throw Span::SpanElementException();
	//				nbr		,   index;
	int	nbr1[2] = {this->tab[0], 0}; // Min 1
	int	nbr2[2] = {this->tab[1], 1}; // Min 2 > Min 1
	if (this->tab[1] < this->tab[0])
	{
		nbr1[0] = this->tab[1];
		nbr1[1] = 1;
		nbr2[0] = this->tab[0];
		nbr2[1] = 0;
	}
	for (unsigned i = 2; i < this->tab.size(); ++i)
	{
		if (this->tab[i] < nbr1[0])
		{
			if (nbr1[0] < nbr2[0])
			{
				nbr2[0] = nbr1[0];
				nbr2[1] = nbr1[1];
			}
			nbr1[0] = this->tab[i];
			nbr1[1] = i;
		}
		else if (this->tab[i] < nbr2[0])
		{
			nbr2[0] = this->tab[i];
			nbr2[1] = i;
		}
	}
	int	min = (nbr2[1] - nbr1[1]);
	return (min);
}

int		Span::longestSpan()
{
	if (this->tab.size() <= 1)
		throw Span::SpanElementException();
	int	nbr1[2] = {this->tab[0], 0}; // Min 1
	int	nbr2[2] = {this->tab[1], 1}; // Max 1
	if (this->tab[1] < this->tab[0])
	{
		nbr1[0] = this->tab[1];
		nbr1[1] = 1;
		nbr2[0] = this->tab[0];
		nbr2[0] = 0;
	}
	for (unsigned int i = 2; i < this->tab.size(); ++i)
	{
		if (this->tab[i] < nbr1[0])
		{
			nbr1[0] = this->tab[i];
			nbr1[1] = i;
		}
		if (this->tab[i] > nbr2[0])
		{
			nbr2[0] = this->tab[i];
			nbr2[1] = i;
		}
	}
	return (nbr2[1] > nbr1[1] ? nbr2[1] - nbr1[1] : nbr1[1] - nbr2[1]);
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
