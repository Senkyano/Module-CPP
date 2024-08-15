/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:29:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/15 14:46:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHealth(100);
	setEnergy(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " quit the profession !" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " is asking for a high five!" << std::endl;
}
