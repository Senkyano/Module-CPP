/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 15:31:38 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::fstream	dataFile;
	std::string		line;

	std::cout << GR << "Default constructor call" << RST << std::endl;

	dataFile.exceptions(std::ifstream::badbit);
	dataFile.open("data.csv", std::ios::in);
	if (!dataFile.is_open())
		throw	BitcoinExchange::OpenFileException();
	while (std::getline(dataFile, line))
	{
		if (line != "date,exchange_rate")
		{
			std::cout << line << std::endl;
			// traitement de la data YYYY-MM-DD
			// make date
			// take value btc
		}
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// this->dataCsv = src.getData();
	(void)src;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "Destructor call\n" << RST;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	// if (*this != src) {}
	return (*this);
}

std::deque<t_data>	BitcoinExchange::getData()
{
	return (this->dataCsv);
}

const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return (RED "Error opening file" RST);
}
