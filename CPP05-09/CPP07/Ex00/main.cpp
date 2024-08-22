/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:25:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/22 22:32:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main()
{
	int	a = 2;
	int	b = 3;
	char	c = 'a';
	char	d = 'b';
	std::string	e1 = "chaine1";
	std::string	e2 = "chaine2";

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min = " << min(a, b) << std::endl;
	std::cout << "max = " << max(a, b) << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min = " << min(c, d) << std::endl;
	std::cout << "max = " << max(c, d) << std::endl;
	std::cout << "e1 = " << e1 << ", e2 = " << e2 << std::endl;
	swap(e1, e2);
	std::cout << "e1 = " << e1 << ", e2 = " << e2 << std::endl;
	std::cout << "min = " << min(e1, e2) << std::endl;
	std::cout << "max = " << max(e1, e2) << std::endl;
}