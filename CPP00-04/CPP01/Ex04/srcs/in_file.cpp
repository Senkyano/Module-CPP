/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_file.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:05:03 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/26 23:09:00 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "analyse.hpp"
#include <fstream>
#include <string>

int	analyse(std::fstream &in_file, std::fstream &out_file, std::string s1, std::string s2)
{
	std::string		line;
	size_t			pos;

	pos = 0;
	while (std::getline(in_file, line))
	{
		while (pos != std::string::npos)
		{
			pos = (line).find(s1);
			if (pos == std::string::npos)
				break;
			line.erase(pos, s1.length());
			if (!line.empty())
				line.insert(pos, s2);
		}
		out_file << line;
		if (!in_file.eof())
			out_file << std::endl;
	}
	return (0);
}
