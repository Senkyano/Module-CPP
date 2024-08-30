/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 11:46:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "main.hpp"

Character::Character()
{
	std::cout << GR << "Character joined the game !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for	(int i = 0; i < 20; i++)
		this->ownWorld[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	std::cout << GR << "Character Default " << name << " joined the game !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for	(int i = 0; i < 20; i++)
		this->ownWorld[i] = NULL;
}

Character::Character(const Character &value)
{
	std::cout << GR << "Character Copy " << value.name << " joined the game !" << RST << std::endl;
	this->name = value.name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 20; i++)
		this->ownWorld[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (value.inventory[i])
			this->inventory[i] = value.inventory[i]->clone();
	}
	for (int i = 0; i < 20; i++)
	{
		if (value.ownWorld[i])
			this->ownWorld[i] = value.ownWorld[i]->clone();
	}
}

Character	&Character::operator=(const Character &value)
{
	name = value.name;
	for (int i = 0; i < 4; i++)
	{
		if (value.inventory[i])
			this->inventory[i] = value.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < 20; i++)
	{
		if (value.ownWorld[i])
			this->ownWorld[i] = value.ownWorld[i]->clone();
		else
			this->ownWorld[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << RED << "Character " << name << " disconnected !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	for (int i = 0; i < 20; i++)
	{
		if (ownWorld[i])
			delete ownWorld[i];
	}
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void				Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
		else if (this->inventory[i] && i == 3)
		{
			std::cout << BLK << "Inventory is full" << std::endl;
			std::cout << "Absorbing by the void..." << RST << std::endl;
			delete m;
		}
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->transfertMateria(this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
	else if (idx >= 0 && idx < 4)
		std::cout << BLK << "Inventory slot is already empty" << RST << std::endl;
	else
		std::cout << RED << "Invalid inventory slot" << RST << std::endl;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else if (idx >= 0 && idx < 4)
		std::cout << BLK << "Inventory slot is empty" << RST << std::endl;
	else
		std::cout << RED << "Invalid inventory slot" << RST << std::endl;
}

void	Character::transfertMateria(AMateria* m)
{
	for (int i = 0; i < 20; i++)
	{
		if (!this->ownWorld[i])
		{
			this->ownWorld[i] = m;
			break ;
		}
		else if (this->ownWorld[i] && i == 19)
		{
			std::cout << BLK << "OwnWorld is full" << std::endl;
			std::cout << "Absorbing by the void..." << RST << std::endl;
			delete m;
		}
	}
}

AMateria	*Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->inventory[idx]);
	else
		return (NULL);
}
