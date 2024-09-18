/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:54:07 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 13:48:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN &src)
{
	(void)src;
}

RPN::~RPN() {};

RPN	&RPN::operator=(const RPN &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

bool	RPN::parsing(const char* str, int i)
{
	int	k = 0, num = 0;

	while (str[k] && !isdigit(str[k]))
		k++;
	for (int p = k + 1; str[p]; ++p)
	{
		if (isdigit(str[p]))
			num++;
		else if (str[p] == '+' || str[p] == '-' || str[p] == '*' || str[p] == '/')
		{
			if (!num)
				return (false);
			num--;
		}
	}
	for (int x = i - 1; x >= 0; --x)
	{
		if (isdigit(str[x]))
		{
			if (str[x - 1] != ' ' && (x - 1) == 0)
				return (false);
			this->num.push(str[x] - '0');
		}
		else if ((str[x] == '+' || str[x] == '-' || str[x] == '*' || str[x] == '/') && str[x - 1] == ' ')
			this->ope.push(str[x]);
		else if (str[x] != ' ')
			return (false);
	}
	if (this->num.size() != (this->ope.size() + 1))
		return (false);
	return (true);
}

void	RPN::calcul(std::string str)
{
	const char*	astra = str.c_str();
	if (!this->parsing(astra, str.size()))
	{
		std::cout << RED << "Error\n" << RST;
		return ;
	}
	int	result = this->num.top();
	this->num.pop();
	while (this->num.size() && this->ope.size())
	{
		char	oper = this->ope.top();
		if (oper == '+')
			result = result + this->num.top();
		else if (oper == '-')
			result = result - this->num.top();
		else if (oper == '*')
			result = result * this->num.top();
		else if (oper == '/')
		{
			if (this->num.top() == 0)
			{
				std::cout << RED << "\rResult : Error\n" << RST;
				return ;
			}
			result = result / this->num.top();
		}
		this->num.pop();
		this->ope.pop();
	}
	std::cout << GR << "\rResult : " << result << RST << std::endl;
}
