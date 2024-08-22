/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:43:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/23 01:19:19 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{
	private :
		T				*array;
		unsigned int	sizeArray;

	public :
		Array(): sizeArray(0) {
			this->array = new T[0];
		};
		Array(unsigned int n): sizeArray(n) {
			this->array = new T[n];
		};
		Array(Array const &other) {
			this = other;
		};
		~Array() {};
		
// setter
		void	setArray(T *array) {
			this->array = array;
		};
//operator
		T	operator[](int i) {
			if (i < 0 || i >= (int)sizeArray)
				throw IndexOutRange();
			return (this->array[i]);
		};
		
// member function
		unsigned int	size(void) {
			return (this->sizeArray);
		};

// exception
	class	IndexOutRange : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return ("Index out of range");
			}	
	};
};

#endif
