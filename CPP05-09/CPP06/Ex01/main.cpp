/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:12:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 14:07:08 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Serialization.hpp"

int	main(void)
{
	Data		data;
	
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";
	int		i = 100;
	
	std::cout << Y << "Data : Before Serialization" << RST << std::endl;
	std::cout << "s1 : " << data.s1 << std::endl;
	std::cout << "n : " << data.n << std::endl;
	std::cout << "s2 : " << data.s2 << std::endl;

	uintptr_t	raw = Serialization::serialize(&data);

	std::cout << "Raw : " << raw << std::endl;

	Data*		ptr = Serialization::deserialize(raw);
	
	std::cout << GR << "Data : After Deserialization" << RST << std::endl;
	std::cout << "s1 : " << ptr->s1 << std::endl;
	std::cout << "n : " << ptr->n << std::endl;
	std::cout << "s2 : " << ptr->s2 << std::endl;
	return (0);
}