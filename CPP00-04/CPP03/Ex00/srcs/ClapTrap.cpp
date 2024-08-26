/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 16:50:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
{
	this->name = name;
	this->health = 10;
	this->engergy = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " appears !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &value)
{
	this->name = value.name;
	this->health = value.health;
	this->engergy = value.engergy;
	this->attack_damage = value.attack_damage;
	std::cout << "ClapTrap " << this->name << " appears !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " disappears !" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->health > 0)
		std::cout << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health > 0)
	{
		std::cout << "Claptrap " << this->name << " takes " << amount << " points of damage du cailloux Celeste" << std::endl;
		this->health -= amount;
		if (this->health <= 0)
			std::cout << "Claptrap " << this->name << " is dead !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->health > 0)
	{
		std::cout << "Claptrap " << this->name << " is repaired for " << amount << " points of health !" << std::endl;
		this->health += amount;
	}
}
