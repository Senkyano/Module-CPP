/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:10:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:13:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected :

	private :

	public :
		WrongCat() : WrongAnimal("Cat") {};
		WrongCat(const WrongCat &value) : WrongAnimal(value) {};
		WrongCat &operator=(const WrongCat &value) { type = value.getType(); return *this; };
		~WrongCat() {};

		void		makeSound() const
		{
			std::cout << "Miaou Miaou" << std::endl;
		}
};

#endif