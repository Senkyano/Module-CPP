/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/22 23:32:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "main.hpp"
# include <vector>
# include <deque>

class	PMergeMe
{
	private :
		std::string lstNum;
		
	public :
		PMergeMe();
		PMergeMe(const char **argv, int argc);
		PMergeMe(const PMergeMe &src);
		
		~PMergeMe();
		
		PMergeMe	&operator=(const PMergeMe &src);

		// BOTH
		std::string	getLstNum();
		template<typename T>
		bool	containerSorted(T &container)
		{
			try {
				typename T::iterator it, it2;
				for (it = container.begin(); it != container.end(); it++)
				{
					for (it2 = it + 1; it2 != container.end(); it2++)
					{
						if (*it > *it2)
							return (false);
					}
				}
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			return (true);
		};
		template<typename T>
		void	printContainer(T &container)
		{
			try {
				for (typename T::iterator it = container.begin(); it != container.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		};
		// Vector
		void	fillContainerVec(std::vector<int> &container);
		void	sortVector(std::vector<int> &container);
		// DEQUE
		void	fillContainerDeque(std::deque<int> &container);
		void	sortDeque(std::deque<int> &container);
};

class	NoNumber : public std::exception {
	virtual const char *what() const throw();
};

class	NotANumber : public std::exception {
	virtual const char *what() const throw();
};

#endif