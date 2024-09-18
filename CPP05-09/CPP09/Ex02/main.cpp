/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:41:18 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 13:33:51 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int	main(int argc, const char **argv)
{
	try {
		std::vector<int>	container;
		PMergeMe			ford(argv, argc);

		ford.fillContainerVec(container);
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
