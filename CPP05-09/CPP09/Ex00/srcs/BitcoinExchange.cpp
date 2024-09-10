/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/10 17:57:03 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange()
{
	std::fstream	dataFile;
	std::string		line;
	t_data			tmp;

	std::cout << GR << "Default constructor call" << RST << std::endl;

	dataFile.exceptions(std::ifstream::badbit);
	dataFile.open("data.csv", std::ios::in);
	if (!dataFile.is_open())
		throw	BitcoinExchange::OpenFileException();
	while (std::getline(dataFile, line))
	{
		if (line != "date,exchange_rate" && /*In norm of date*/)
		{
			// std::cout << line << std::endl;
			size_t pos = (line).find("-");
			tmp.years = std::atoi(line.c_str());
			tmp.months = std::atoi(line.c_str() + pos + 1);
			tmp.days = std::atoi(line.c_str() + pos + 4);
			tmp.value_btc = std::atof(line.c_str() + pos + 7);
			// traitement de la data YYYY-MM-DD
			// take value btc
			if (this->correctData(tmp))
				this->dataCsv.push_back(tmp);
		}
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// this->dataCsv = src.getData();
	(void)src;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "Destructor call\n" << RST;
}

// Operator Assign
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	// if (*this != src) {}
	return (*this);
}

// Member function
std::deque<t_data>	BitcoinExchange::getData()
{
	return (this->dataCsv);
}

bool				BitcoinExchange::correctData(t_data src)
{
	
}

bool				BitcoinExchange::in_normDate(std::string line)
{
	
}

// Exception
const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return (RED "Error opening file" RST);
}
