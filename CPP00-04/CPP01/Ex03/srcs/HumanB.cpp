/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:13:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/24 17:23:39 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weaponSet = false;
}

HumanB::~HumanB()
{
	
}

void	HumanB::attack()
{
	if (this->weaponSet == false)
		std::cout << this->name << " attacks with is fists !!" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
	this->weaponSet = true;
}
