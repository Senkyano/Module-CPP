/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:10:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 10:06:31 by rihoy            ###   ########.fr       */
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
		WrongCat();
		WrongCat(const WrongCat &value);
		WrongCat &operator=(const WrongCat &value);
		~WrongCat();

		void		makeSound() const;
};

#endif