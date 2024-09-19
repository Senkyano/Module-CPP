/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:36:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 15:46:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "main.hpp"
# include <vector>
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
		void	addNumber1(int nbr_arg, ...);
		void	addNumber(int nbr);
		void	addNumber(std::vector<int> other);
		void	addNumber(Span &other);
		void	addNumberRandom(int nbr, unsigned int many);
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