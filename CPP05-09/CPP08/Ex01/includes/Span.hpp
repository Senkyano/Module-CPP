/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:36:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/05 01:09:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "main.hpp"
# include <vector>
# include <algorithm>
# include <limits>

class	Span
{
	private :
		unsigned int		size;
		std::vector<int>	tab;

	public :
	// Constructor
		Span();
		Span(unsigned int n);
		Span(const Span &value);
		Span	&operator=(Span const &value);

	// Destructor
		~Span();
	
	// Member function
		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();

	//exception
	class	SpanElementException : public std::exception
	{
		public :
			virtual	const char *what() const throw();
	};
	class	SpanOccupedException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class	SpanFullException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class	SpanOutException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
};

#endif