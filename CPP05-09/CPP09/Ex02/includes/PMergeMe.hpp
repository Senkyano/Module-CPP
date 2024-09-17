/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/17 16:41:28 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "main.hpp"
# include <vector>
# include <list>

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

		std::string	getLstNum();
		// Vector
		void	fillContainerVec(std::vector<int> &container);
		// List
};

class	NoNumber : public std::exception {
	virtual const char *what() const throw();
};

class	NotANumber : public std::exception {
	virtual const char *what() const throw();
};

#endif