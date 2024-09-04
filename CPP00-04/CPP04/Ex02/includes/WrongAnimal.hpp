/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:09:55 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 10:06:22 by rihoy            ###   ########.fr       */
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
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &value);
		WrongAnimal &operator=(const WrongAnimal &value);
		~WrongAnimal();

		void	makeSound() const;
		std::string	getType() const;
};

#endif
