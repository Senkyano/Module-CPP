/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:04:07 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/26 16:07:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "analyse.hpp"
bool	opening_file(std::fstream &file, std::fstream &out_file, char **argv);

int	main(int argc, char **argv)
{
	std::fstream 		in_file;
	std::fstream		out_file;

	if (argc != 4)
	{
		std::cout << "Needed FILENAME <string1> <string2>" << std::endl;
		return (1);
	}
	if (!opening_file(in_file, out_file, argv))
		return (1);
	analyse(in_file, out_file, argv[2], argv[3]);
	in_file.close();
	out_file.close();
	return (0);
}

bool	opening_file(std::fstream &in_file, std::fstream &out_file, char** argv)
{
	std::string			newfilename;

	newfilename = std::string(argv[1]) + ".replace";
	in_file.open(argv[1], std::ios::in);
	if (!in_file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (false);
	}
	out_file.open(newfilename.c_str(), std::ios::out);
	if (!out_file.is_open())
	{
		std::cout << "Error creating file" << std::endl;
		return (false);
	}
	return (true);
}
