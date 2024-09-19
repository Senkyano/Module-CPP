/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:31:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 11:18:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>

int	main(void)
{
	std::vector<int>	tab(16,0);
	std::list<int>		tab2;
	int					elements[12] = {23, 6, 5, 1, -23, 56, 4, 6, 8, 9, 0, 12};

    for (int i = 0; i < 12; ++i)
	{
        tab2.push_back(elements[i]);
	}

	for (unsigned int i = 0 ; i < tab.size() ; ++i)
	{
		tab[i] += i;
	}

	std::cout << PUR << "Vector" << RST << std::endl;
	easyfind(tab, 13);
	easyfind(tab, 1);
	easyfind(tab, 3);
	easyfind(tab, 56);
	easyfind(tab, -1);
	std::cout << PUR << "List" << RST << std::endl;
	easyfind(tab2, -23);
	easyfind(tab2, -2);
	easyfind(tab2, 6);
	easyfind(tab2, 56);
}
