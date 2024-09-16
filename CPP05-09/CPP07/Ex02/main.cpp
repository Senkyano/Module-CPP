/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:39:07 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/16 16:59:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	int	array[5] = {1, 2, 3, 4, 5};
	std::string	str[5] = {"hello", "ca", "va", "?", "!"};


	(void)array;
	(void)str;
	Array<int> arr(5);
	Array<std::string> arr2(5);

	(void)arr;
	(void)arr2;
	arr.setArray(array);
	arr2.setArray(str);
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	for (unsigned int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << std::endl;
	
	return (0);
}
