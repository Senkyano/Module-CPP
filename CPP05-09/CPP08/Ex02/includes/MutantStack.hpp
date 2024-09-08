/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:52:59 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/07 19:56:39 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "main.hpp"
# include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public :
		// Constructeur
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T> &src);
		
		// Destructeur
		~MutantStack<T>();

		// Operator Assign
		MutantStack<T>&operator=(const MutantStack<T> &src);
		
};

#endif