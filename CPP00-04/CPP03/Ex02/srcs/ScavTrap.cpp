/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:59:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 16:49:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	setHealth(100);
	setEnergy(50);
	setAttackDamage(20);
	this->guard = false;
	std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &value) : ClapTrap(value)
{
	setHealth(value.getHealth());
	setEnergy(value.getEnergy());
	setAttackDamage(value.getAttackDamage());
	this->guard = value.guard;
	std::cout << "ScavTrap " << getName() << " is born!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " is dead!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->guard == false)
	{	
		this->guard = true;
		std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode!" << std::endl;
	}
	else
	{
		this->guard = false;
		std::cout << "ScavTrap " << getName() << " has quit his post!" << std::endl;
	}
}
