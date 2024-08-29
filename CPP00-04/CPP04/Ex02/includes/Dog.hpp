/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:02 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/29 15:27:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	protected :

	private :
		Brain	*brain;
	
	public :
		Dog();
		Dog(const Dog &value);
		Dog &operator=(const Dog &value);
		~Dog();
		
		void	makeSound() const;
		Brain	*getBrain() const;
		std::string	getIdea(int i);
		void	addIdea(int i, std::string idea);
};

#endif