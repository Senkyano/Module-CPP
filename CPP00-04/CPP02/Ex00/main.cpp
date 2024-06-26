/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:13:11 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/27 21:53:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canonique.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int main( void )
{
	Canonique	a;
	Canonique	b( a );
	Canonique	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
