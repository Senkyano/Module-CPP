/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:25:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/19 15:59:21 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include "main.hpp"
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

class	MyException : public std::exception
{
	public :
		virtual const char *what() const throw() {
			return ("No occurrence of ");
		};
};

template <typename T>
void	easyfind(T &container, int n)
{
	try
	{
		typename T::iterator it = std::find(container.begin(), container.end(), n);
		if (it == container.end())
			throw MyException();
		std::cout << GR << "Element found : " << *it << RST << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << n << RST << std::endl;
	}
}

#endif
