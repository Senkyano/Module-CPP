/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:01 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 13:25:24 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "main.hpp"
# include <fstream>
# include <ctime>
# include <map>

typedef struct s_data
{
	unsigned int	years;
	unsigned int	months;
	unsigned int	days;
} t_data;

class BitcoinExchange
{
	private:
		std::map<std::string, double>	dataCsv;

	public:
	// Constructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);

	// Destructor
		~BitcoinExchange();

	// Operator Assign
		BitcoinExchange	&operator=(const BitcoinExchange &src);
	
	// Member function
		std::map<std::string, double>	getData();
		bool					correctData(std::string date);
		bool					in_normLigne(const char *line);
		bool					in_normData(std::string line, int method);
		void					evolution_Wallet(std::string file);
		double					srch_prochData(std::string date);

	class	OpenFileException : public std::exception {
		public :
			virtual const char *what() const throw();
	};
};

#endif