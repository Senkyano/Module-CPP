/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:54:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:00:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected :
		std::string type;

	private :

	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal &value);
		Animal &operator=(const Animal &value);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif