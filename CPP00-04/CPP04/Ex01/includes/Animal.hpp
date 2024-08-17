/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:54:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/17 14:53:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class	Animal
{
	protected :
		std::string type;

	private :
		Brain	*brain;

	public :
		Animal();
		Animal(std::string type);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		void			setIdeaAnimal(int i, std::string idea);
		std::string		getIdeaAnimal(int i);
};

#endif