/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:44:10 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/22 23:25:03 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print(int &i)
{
	std::cout << i << std::endl;
}

void	printstd(std::string &str)
{
	std::cout << str << std::endl;
}

int	main()
{
	int		array[5] = {1, 2, 3, 4, 5};
	std::string	str[5] = {"hello", "ca", "va", "?", "!"};

	iter(array, 5, print);
	std::cout << std::endl;
	iter(str, 5, printstd);
	return (0);
}
