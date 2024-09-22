/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/22 23:33:00 by rihoy            ###   ########.fr       */
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

void	PMergeMe::sortVector(std::vector<int> &container)
{
	if (this->containerSorted(container) || container.size() < 2)
		return ;
	
	std::vector<int>			largestContain;
	std::vector<int>			smallestContain;
	std::vector<int>::iterator	it;

	for (it = container.begin(); it != container.end(); it += 2)
	{
		if (it == container.end() - 1)
		{
			smallestContain.push_back(*it);
			break ;
		}
		else if ((*it) > *(it + 1))
		{
			largestContain.push_back(*it);
			smallestContain.push_back(*(it + 1));
		}
		else if ((*it) < *(it + 1))
		{
			largestContain.push_back(*(it + 1));
			smallestContain.push_back(*it);
		}
		if (it == container.end() - 2)
			break ;
	}
	this->sortVector(largestContain);
	for (it = smallestContain.begin(); it != smallestContain.end(); it++)
	{
		std::size_t	start = 0, end = largestContain.size(), mid;
		while (end > start)
		{
			mid = (start + end) / 2;
			if (*it < largestContain[mid])
				end = mid;
			else if (*it >= largestContain[mid])
				start = mid + 1;
		}
		largestContain.insert(largestContain.begin() + start, *it);
	}
	container = largestContain;
}

// LIST
void	PMergeMe::fillContainerDeque(std::deque<int> &container)
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

void	PMergeMe::sortDeque(std::deque<int> &container)
{
	if (this->containerSorted(container) || container.size() < 2)
		return ;
	
	std::deque<int>			largestContain;
	std::deque<int>			smallestContain;
	std::deque<int>::iterator	it;

	for (it = container.begin(); it != container.end(); it += 2)
	{
		if (it == container.end() - 1)
		{
			smallestContain.push_back(*it);
			break ;
		}
		else if ((*it) > *(it + 1))
		{
			largestContain.push_back(*it);
			smallestContain.push_back(*(it + 1));
		}
		else if ((*it) < *(it + 1))
		{
			largestContain.push_back(*(it + 1));
			smallestContain.push_back(*it);
		}
		if (it == container.end() - 2)
			break ;
	}
	this->sortDeque(largestContain);
	for (it = smallestContain.begin(); it != smallestContain.end(); it++)
	{
		std::size_t	start = 0, end = largestContain.size(), mid;
		while (end > start)
		{
			mid = (start + end) / 2;
			if (*it < largestContain[mid])
				end = mid;
			else if (*it >= largestContain[mid])
				start = mid + 1;
		}
		largestContain.insert(largestContain.begin() + start, *it);
	}
	container = largestContain;
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
