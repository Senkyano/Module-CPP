/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/18 12:40:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "main.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GR << "Master : MateriaSource constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "Master : MateriaSource destructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete this->inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	std::cout << Y << "MateriaSource : Learning " << materia->getType() << "..." << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = materia;
			break ;
		}
		else if (this->inventory[i] && i == 3)
		{
			std::cout << BLK << "Inventory is full" << std::endl;
			std::cout << "Absorbing by the void..." << RST << std::endl;
			delete materia;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (NULL);
}
