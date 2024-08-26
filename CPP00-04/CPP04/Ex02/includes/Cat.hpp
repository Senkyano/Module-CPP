/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:52:10 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:03:23 by rihoy            ###   ########.fr       */
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

	public :
		Cat();
		Cat(const Cat &value);
		Cat &operator=(const Cat &value);
		~Cat();

		void		makeSound() const;
};

#endif
