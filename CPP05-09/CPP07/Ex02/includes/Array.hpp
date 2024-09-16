/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:43:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/16 16:58:51 by rihoy            ###   ########.fr       */
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
			this->sizeArray = other.sizeArray;
			this->array = new T[other.sizeArray];
			if (other->sizeArray != 0)
			{
				for (unsigned int i = 0; i < this->sizeArray; ++i)
					this->array[i] = other.array[i];
			}
		};
		Array	&operator=(Array const &other)
		{
			if (other.size() != 0)
			{
				this->sizeArray = other.sizeArray;
				this->array = new T[other.sizeArray];
				for (unsigned int i = 0; i < other.sizeArray; i++)
					this->array[i] = other.array[i];
			}
			return (*this);
		};
		~Array() {
			if (this->array != NULL)
				delete [] this->array;
		};
		
// setter
		void	setArray(T *array) {
			for (unsigned int i = 0; i < this->size(); ++i)
				this->array[i] = array[i];
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
