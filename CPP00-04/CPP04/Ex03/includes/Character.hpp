/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 11:32:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class	Character : public virtual ICharacter
{
	private :
		std::string	name;
		AMateria*	inventory[4];
		AMateria*	ownWorld[20];

	public :
		Character();
		Character(std::string const &name);
		Character(const Character &value);
		Character &operator=(const Character &value);
		~Character();

		std::string const	&getName() const;
		AMateria*			getMateria(int idx) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				transfertMateria(AMateria* m);
};

#endif