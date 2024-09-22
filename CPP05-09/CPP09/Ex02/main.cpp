/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:41:18 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/22 23:35:58 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int	main(int argc, const char **argv)
{
	try {
		std::vector<int>	container;
		PMergeMe			ford(argv, argc);

		clock_t	start, end;
		double	time_vec;
	
		ford.fillContainerVec(container);
		start = clock();
		ford.sortVector(container);
		end = clock();
		time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << GR "Vector : Time to process a range of " << container.size() << " Element, sort in " << time_vec << "µs" RST << std::endl;
		// ford.printContainer(container);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::deque<int>		container1;
		PMergeMe			ford2(argv, argc);

		clock_t	start2, end2;
		double	time_deque2;
	
		ford2.fillContainerDeque(container1);
		start2 = clock();
		ford2.sortDeque(container1);
		end2 = clock();
		time_deque2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;
		std::cout << GR "Deque  : Time to process a range of " << container1.size() << " Element, sort in " << time_deque2 << "µs" RST << std::endl;
		// ford2.printContainer(container1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
