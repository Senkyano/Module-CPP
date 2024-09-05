/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:25:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 23:28:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include "main.hpp"

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
		for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		{
			if (*it == n)
			{
				std::cout << GR << "Element found : " << *it << RST << std::endl;
				return ;
			}
		}
		throw MyException();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << n << RST << std::endl;
	}
}

#endif
