/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 13:56:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange()
{
	std::fstream	dataFile;
	std::string		line;

	std::cout << GR << "Default constructor call" << RST << std::endl;

	dataFile.open("data.csv", std::ios::in);
	if (!dataFile.is_open())
		throw	BitcoinExchange::OpenFileException();
	while (std::getline(dataFile, line))
	{
		if (this->in_normData(line, 0))
		{
			size_t pos = (line).find(",");
			size_t pos2 = (line).find_last_of(" \n\t");
			std::string tmp = line.substr(pos2 + 1, pos - 1);
			double value_btc = std::atof(line.c_str() + (pos + 1));
			if (correctData(tmp))
				this->dataCsv[tmp] = value_btc;
		}
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "Destructor call\n" << RST;
}

// Operator Assign
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

// Member function
std::map<std::string, double>	BitcoinExchange::getData()
{
	return (this->dataCsv);
}

bool				BitcoinExchange::correctData(std::string date)
{
	time_t			actual = std::time(0);
	tm				*ltm = std::localtime(&actual);
	t_data			src;
	unsigned int	month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	src.years = std::atoi(date.c_str());
	src.months = std::atoi(date.c_str() + 5);
	src.days = std::atoi(date.c_str() + 8);
	if (src.years == (unsigned int)(1900 + ltm->tm_year)
		&& ((src.months == (unsigned int)ltm->tm_mon + 1 && (int)src.days > ltm->tm_mday)
			|| (unsigned int)ltm->tm_mon + 1 < src.months))
		return (false);
	if (src.years <= (unsigned int)(1900 + ltm->tm_year))
	{
		if ((src.years % 4) != 0 && src.months == 2 && src.days > 0
			&& src.days > (month_days[1] - 1))
			return (false);
		if ((src.months <= 12 && src.months > 0) && src.days > 0
			&& (month_days[src.months - 1] >= src.days))
			return (true);
	}
	return (false);
}

bool				BitcoinExchange::in_normData(std::string line, int method)
{
	if (12 < line.size() && this->in_normLigne((line).c_str()))
	{
		size_t pos  = (line).find("-");
		size_t pos2 = (line).find("-", pos + 1);
		if (((line).find_last_of(",") != (line).find(","))
			|| ((line).find_last_of("|") != (line).find("|"))
				|| ((line).find_last_of(".") != (line).find(".")))
			return (false);
		if (method == 0)
		{
			size_t pos_start_data = (line).find_last_of(" \n\t") + 1;
			size_t pos3 = (line).find_last_of(",");
			if (pos3 - pos_start_data != 10)
				return (false);
			if (pos != 0 && pos2 != pos
				&& (pos2 - (pos + 1)) == 2 && (pos3 - (pos2 + 1)) == 2)
				return (true);
		}
		else
		{
			if (14 > line.size())
				return (false);
			size_t pos_start_data = (line).find_first_not_of(" \n\t");
			size_t pos3 = (line).find("|");
			if ((pos3) - pos_start_data != 11)
				return (false);
			if (pos != 0 && pos2 != pos
				&& (pos2 - (pos + 1)) == 2 && (pos3 - (pos2 + 1)) == 3)
				return (true);
		}
	}
	return (false);
}

bool			BitcoinExchange::in_normLigne(const char *line)
{
	for (int i = 0; line[i]; ++i)
	{
		if ((line[i] < '0' || line[i] > '9') && line[i] != '|' && line[i] != ','
			&& line[i] != '-' && line[i] != '.' && !isspace(line[i]))
			return (false);
	}
	return (true);
}

void			BitcoinExchange::evolution_Wallet(std::string file)
{
	std::fstream	inputFile;
	std::string		line;

	inputFile.open(file.c_str(), std::ios::in);
	if (!inputFile.is_open())
		throw	BitcoinExchange::OpenFileException();
	while (std::getline(inputFile, line))
	{
		if (this->in_normData(line, 1))
		{
			size_t pos = (line).find("|");
			size_t pos2 = (line).find_first_not_of(" \n\t");
			std::string tmp = line.substr(pos2, pos - 1);
			double value_btc = std::atof(line.c_str() + (pos + 1));
			if (correctData(tmp) && value_btc > 0 && value_btc < 1000)
			{
				std::cout << tmp << " => ";
				double taux = this->srch_prochData(tmp);
				std::cout << taux << " => " << taux * value_btc << std::endl;
			}
			else
			{
				if (value_btc < 0)
					std::cout << RED << "Error : not a positive number.\n" << RST;
				else if (value_btc > 1000)
					std::cout << RED << "Error : too large number.\n" << RST;
				else
					std::cout << RED << "Error : bad input => " << tmp << RST << std::endl;
			}
		}
		else
			std::cout << RED << "Error : bad input => " << line << RST << std::endl;
	}
}

double			BitcoinExchange::srch_prochData(std::string date)
{
	std::map<std::string, double>	tmp = this->dataCsv;
	double							prch_value = 0;

	for (std::map<std::string, double>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if (date >= it->first)
			prch_value = it->second;
	}
	return (prch_value);
}

// Exception
const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return (RED "Error opening file" RST);
}
