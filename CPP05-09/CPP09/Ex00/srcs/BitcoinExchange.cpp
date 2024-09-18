/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 18:55:41 by rihoy            ###   ########.fr       */
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
			std::string tmp = line.substr(0, pos);
			double value_btc = std::atof(line.c_str() + pos);
			std::cout << tmp << std::endl;
			(void)value_btc;
			// if (this->correctData(tmp) && value_btc >= 0)
			// 	this->dataCsv[tmp] = value_btc;
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

bool				BitcoinExchange::correctData(t_data src)
{
	time_t			actual = std::time(0);
	tm				*ltm = std::localtime(&actual);
	unsigned int	month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (src.years == (unsigned int)(1900 + ltm->tm_year)
		&& ((src.months == (unsigned int)ltm->tm_mon + 1 && (int)src.days >= ltm->tm_mday)
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
			size_t pos3 = (line).find_last_of(",");
			if (pos != 0 && pos2 != pos
				&& (pos2 - (pos + 1)) == 2 && (pos3 - (pos2 + 1)) == 2)
				return (true);
		}
		else
		{
			if (14 > line.size())
				return (false);
			size_t pos3 = (line).find_last_of("|");
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
		if (!isdigit(line[i]) && line[i] != '|' && line[i] != ','
			&& line[i] != '-' && line[i] != '.' && !isspace(line[i]))
			return (false);
	}
	return (true);
}

void			BitcoinExchange::evolution_Wallet(std::string file)
{
	// std::fstream	inputFile;
	// std::string		line;
	// t_data			tmp;
	(void)file;
	// inputFile.open(file.c_str(), std::ios::in);
	// if (!inputFile.is_open())
	// 	throw	BitcoinExchange::OpenFileException();
	// while (std::getline(inputFile, line))
	// {
	// 	if (this->in_normData(line, 1))
	// 	{
	// 		size_t pos = (line).find("-");
	// 		tmp.years = std::atoi(line.c_str());
	// 		tmp.months = std::atoi(line.c_str() + pos + 1);
	// 		tmp.days = std::atoi(line.c_str() + pos + 4);
	// 		tmp.value_btc = std::atof(line.c_str() + pos + 9);
	// 		if (this->correctData(tmp))
	// 			this->exchange(tmp);
	// 	}
	// }
}

t_data			BitcoinExchange::srch_prochData(t_data src)
{
	return (src);
	// std::map<t_data, double>	tmp = this->dataCsv;
	// t_data				proch = {0,0,0,0};

	// for (std::map<t_data, double>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	// {
	// 	t_data	actual = *it;

	// 	if (actual.years >= src.years && (actual.months > src.months || (actual.days >= src.days && actual.months == src.months)))
	// 		return (proch);
	// 	proch = *it;
	// }
	// return (proch);
}

void			BitcoinExchange::exchange(t_data src)
{
	(void)src;
	// t_data	tmp = this->srch_prochData(src);
	// (void)tmp;
	// if (src.value_btc < 0)
	// 	std::cout << RED << "Error : not a positif number\n" << RST;
	// else if (src.value_btc > 1000)
	// 	std::cout << RED << "Error : too large number\n" << RST;
	// else
	// {
	// 	std::cout << GR << tmp.years << "-";
	// 	std::cout << tmp.months << "-";
	// 	std::cout << tmp.days << " => ";
	// 	std::cout << src.value_btc << " = " << tmp.value_btc * src.value_btc << "$" << RST <<std::endl;
	// }
}

// Exception
const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return (RED "Error opening file" RST);
}
