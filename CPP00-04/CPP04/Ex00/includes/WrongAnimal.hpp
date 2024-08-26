/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:09:55 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:13:19 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected :
		std::string type;

	private :

	public :
		WrongAnimal()
		{
			std::cout << "WrongAnimal constructor called" << std::endl;
		}
		WrongAnimal(std::string type)
		{
			std::cout << "WrongAnimal constructor called" << std::endl;
		}
		WrongAnimal(const WrongAnimal &value)
		{
			std::cout << "WrongAnimal copy constructor called" << std::endl;
		}
		WrongAnimal &operator=(const WrongAnimal &value)
		{
			std::cout << "WrongAnimal assignation operator called" << std::endl;
			return *this;
		}
		~WrongAnimal() {};

		void	makeSound() const
		{
			std::cout << "WrongAnimal makes a sound" << std::endl;
		}
		std::string	getType() const
		{
			return type;
		}
};

#endif
