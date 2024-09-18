/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 13:35:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

// CONSTRUCTOR
PMergeMe::PMergeMe() {
}

PMergeMe::PMergeMe(const char **argv, int argc) {
	if (argc == 1)
		throw NoNumber();
	std::string input;

	for (int i = 1; i < argc; ++i)
	{
		if (argv[i])
		{
			for (int x = 0; argv[i][x]; ++x)
			{
				if (!isspace(argv[i][x]) && (!isdigit(argv[i][x]) || argv[i][x] == '-'))
					throw NotANumber();
			}
			input += std::string(argv[i]);
			input += ' ';
		}
	}
	this->lstNum = input;
}

PMergeMe::PMergeMe(const PMergeMe &src) {
	*this = src;
}

// DESTRUCTOR
PMergeMe::~PMergeMe() {
}

// OPERATOR ASSIGN
PMergeMe	&PMergeMe::operator=(const PMergeMe &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

// MEMBER FUNCTION
std::string	PMergeMe::getLstNum()
{
	return (this->lstNum);
}

// VECTOR
void	PMergeMe::fillContainerVec(std::vector<int> &container)
{
	for (unsigned int i = 0; i < this->lstNum.length(); ++i)
	{
		if (isdigit(this->lstNum[i]))
		{
			std::string tmp;
			while (isdigit(this->lstNum[i]))
			{
				tmp += this->lstNum[i];
				++i;
			}
			container.push_back(atoi(tmp.c_str()));
		}
	}
}

// EXCEPTION
const char	*NoNumber::what() const throw()
{
	return (RED "Error : No Number" RST);
}

const char	*NotANumber::what() const throw()
{
	return (RED "Error : Need to contain only number or positive number" RST);
}
