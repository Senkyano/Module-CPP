/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/11 13:17:48 by rihoy            ###   ########.fr       */
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
		if (line != "date,exchange_rate" && this->in_normData(line, 0))
		{
			size_t pos = (line).find("-");
			tmp.years = std::atoi(line.c_str());
			tmp.months = std::atoi(line.c_str() + pos + 1);
			tmp.days = std::atoi(line.c_str() + pos + 4);
			tmp.value_btc = std::atof(line.c_str() + pos + 7);
			if (this->correctData(tmp))
				this->dataCsv.push_back(tmp);
		}
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->dataCsv = src;
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
	if (this != src)
	return (*this);
}

// Member function
std::deque<t_data>	BitcoinExchange::getData()
{
	return (this->dataCsv);
}

bool				BitcoinExchange::correctData(t_data src)
{
	unsigned int	month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if ((src.months <= 12 && src.months > 0) && src.days > 0
		&& month_days[src.months - 1] >= src.days)
		return (true);
	return (false);
}

bool				BitcoinExchange::in_normData(std::string line, int method)
{
	if (12 < line.size())
	{
		if (method == 0)
		{
			size_t pos  = (line).find("-");
			size_t pos2 = (line).find_last_of("-");
			size_t pos3 = (line).find_last_of(",");
			if (pos != 0 && pos2 != pos
				&& (pos2 - (pos + 1)) == 2 && (pos3 - (pos2 + 1)) == 2)
				return (true);
		}
		else
		{
			if (14 > line.size())
				return (false);
			size_t pos  = (line).find("-");
			size_t pos2 = (line).find_last_of("-");
			size_t pos3 = (line).find_last_of("|");
			if (pos != 0 && pos2 != pos
				&& (pos2 - (pos + 1)) == 2 && (pos3 - (pos2 + 1)) == 3)
				return (true);
		}
	}
	return (false);
}

// Exception
const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return (RED "Error opening file" RST);
}
