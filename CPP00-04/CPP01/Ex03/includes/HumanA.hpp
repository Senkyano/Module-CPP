/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:52:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/26 14:53:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__HUMAN_A_HPP__
# define __HUMAN_A_HPP__

# include <string>
# include <iostream>

# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
			~HumanA();

		void	attack();
		void	setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif
