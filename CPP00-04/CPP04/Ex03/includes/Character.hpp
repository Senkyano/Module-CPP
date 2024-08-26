/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:04:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private :
		std::string	name;
		AMateria*	inventory[4];
		AMateria*	ownWorld[20];

	public :
		Character(std::string const &name);
		Character(const Character &value);
		Character &operator=(const Character &value);
		~Character();

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				transfertMateria(AMateria* m);
};

#endif