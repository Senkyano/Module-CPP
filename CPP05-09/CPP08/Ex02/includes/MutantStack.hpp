/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:52:59 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/09 15:35:10 by rihoy            ###   ########.fr       */
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

		// Iterateur
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator		begin();
		iterator		end();
		const_iterator	cbegin();
		const_iterator	cend();
		// class parent
		// using -> permet de reutiliser les methode de la class parent;
		using	std::stack<T>::push;
		using	std::stack<T>::pop;
		using	std::stack<T>::size;
		using	std::stack<T>::empty;
};

// Constructeur
template<typename T>
MutantStack<T>::MutantStack ()
{}

template<typename T>
MutantStack<T>::MutantStack (const MutantStack<T> &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
	if (this != &src)
		this->c = src.c;
	return (*this);
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin()
{
	return (this->c.cbegin());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend()
{
	return (this->c.cend());
}

#endif