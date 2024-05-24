/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:37:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/24 13:50:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	const &ref = str;

	std::cout << "Address of the string        : " << &str << std::endl;
	std::cout << "Address of ptr of the string : " << ptr << std::endl;
	std::cout << "Address of ref of the string : " << &ref << std::endl;
	std::cout << "String          : " << str << std::endl;
	std::cout << "String with ptr : " << *ptr << std::endl;
	std::cout << "String with ref : " << ref << std::endl;
}