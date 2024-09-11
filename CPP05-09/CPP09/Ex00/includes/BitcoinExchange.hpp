/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:01 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/11 13:02:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "main.hpp"
# include <fstream>
# include <deque>

typedef struct s_data
{
	unsigned int	years;
	unsigned int	months;
	unsigned int	days;
	double				value_btc;
} t_data;

class BitcoinExchange
{
	private:
		std::deque<t_data>	dataCsv;

	public:
	// Constructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);

	// Destructor
		~BitcoinExchange();

	// Operator Assign
		BitcoinExchange	&operator=(const BitcoinExchange &src);
	
	// Member function
		std::deque<t_data>	getData();
		bool				correctData(t_data srcs);
		bool				in_normData(std::string line, int method);

	class	OpenFileException : public std::exception {
		public :
			virtual const char *what() const throw();
	};
};

#endif