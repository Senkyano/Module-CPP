/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:52:10 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 13:19:45 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{	
	protected :

	private :
		Brain	*brain;

	public :
		Cat();
		Cat(const Cat &value);
		Cat &operator=(const Cat &value);
		~Cat();

		void		makeSound() const;
		Brain 		*getBrain() const;
		std::string	getIdea(int i);
		void		addIdea(int i, std::string idea);
};

#endif
