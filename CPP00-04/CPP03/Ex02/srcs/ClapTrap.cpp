/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/15 14:47:00 by rihoy            ###   ########.fr       */
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

void	ClapTrap::setHealth(int health)
{
	this->health = health;
}

void	ClapTrap::setEnergy(int energy)
{
	this->engergy = energy;
}

void	ClapTrap::setAttackDamage(int attack_damage)
{
	this->attack_damage = attack_damage;
}

std::string	ClapTrap::getName()
{
	return (this->name);
}

int	ClapTrap::getHealth()
{
	return (this->health);
}

int	ClapTrap::getEnergy()
{
	return (this->engergy);
}

int	ClapTrap::getAttackDamage()
{
	return (this->attack_damage);
}
